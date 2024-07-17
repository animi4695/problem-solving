#include <iostream>
#include <queue>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

class SupermarketCheckout {
public:
    struct Customer {
        int customerId;
        int lineNumber;
        int numItems;
        bool operator<(const Customer& other) const {
            return customerId < other.customerId;
        }
    };

    unordered_map<int, queue<Customer>> lines; // lineNumber -> queue of customers
    unordered_map<int, Customer> customerMap; // customerId -> customer details
    set<pair<int, int>> customersInStore; // (lineNumber, customerId) to maintain order

    // Customer enters the store and joins a line
    void OnCustomerEnter(int customerId, int lineNumber, int numItems) {
        Customer customer = {customerId, lineNumber, numItems};
        lines[lineNumber].push(customer);
        customerMap[customerId] = customer;
        customersInStore.insert({lineNumber, customerId});
    }

    // Customer changes the number of items in their basket
    void OnBasketChange(int customerId, int newNumItems) {
        Customer& customer = customerMap[customerId];
        if (newNumItems == 0) {
            OnCustomerExit(customerId);
            return;
        }
        
        customer.numItems = newNumItems;
        if (newNumItems > customer.numItems) {
            // Move customer to the back of the line
            int lineNumber = customer.lineNumber;
            queue<Customer> newQueue;
            while (!lines[lineNumber].empty()) {
                Customer frontCustomer = lines[lineNumber].front();
                lines[lineNumber].pop();
                if (frontCustomer.customerId != customerId) {
                    newQueue.push(frontCustomer);
                }
            }
            newQueue.push(customer);
            lines[lineNumber] = newQueue;
        }
    }

    // Process items in a specific line
    void OnLineService(int lineNumber, int numProcessedItems) {
        if (lines[lineNumber].empty()) return;
        queue<Customer> newQueue;
        while (!lines[lineNumber].empty() && numProcessedItems > 0) {
            Customer frontCustomer = lines[lineNumber].front();
            lines[lineNumber].pop();
            if (frontCustomer.numItems > numProcessedItems) {
                frontCustomer.numItems -= numProcessedItems;
                newQueue.push(frontCustomer);
                numProcessedItems = 0;
            } else {
                numProcessedItems -= frontCustomer.numItems;
                OnCustomerExit(frontCustomer.customerId);
            }
        }
        while (!lines[lineNumber].empty()) {
            newQueue.push(lines[lineNumber].front());
            lines[lineNumber].pop();
        }
        lines[lineNumber] = newQueue;
    }

    // Process 1 item from each line
    void OnLinesService() {
        vector<int> lineNumbers;
        for (const auto& pair : lines) {
            lineNumbers.push_back(pair.first);
        }
        for (int lineNumber : lineNumbers) {
            OnLineService(lineNumber, 1);
        }
    }

    // Notify when a customer leaves the store
    void OnCustomerExit(int customerId) {
        Customer customer = customerMap[customerId];
        customersInStore.erase({customer.lineNumber, customerId});
        customerMap.erase(customerId);
        cout << "Customer " << customerId << " has left the store." << endl;
    }
};

int main() {
    SupermarketCheckout supermarket;

    // Example usage:
    supermarket.OnCustomerEnter(1, 2, 5);
    supermarket.OnCustomerEnter(2, 1, 3);
    supermarket.OnBasketChange(1, 7);
    supermarket.OnLineService(2, 3);
    supermarket.OnLinesService();

    return 0;
}
