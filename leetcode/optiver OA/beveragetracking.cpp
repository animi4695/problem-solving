#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <map>

using namespace std;

class BeverageTracker {
private:
    unordered_map<int, unordered_map<string, int>> storeOrders; // storeId -> (beverageName -> quantity)
    unordered_map<string, int> beverageTotals; // beverageName -> total quantity
    int numberOfStores = 0;
    int numberOfOrders = 0;
    int numberOfDifferentBeverages = 0;
    int numberOfBeverages = 0;
    int limitNumberOfStores = 0;
    unordered_map<string, int> limitPerBeverageTotal; // beverageName -> limit

    void closeAllStores() {
        storeOrders.clear();
        beverageTotals.clear();
        numberOfStores = 0;
        numberOfOrders = 0;
        numberOfDifferentBeverages = 0;
        numberOfBeverages = 0;
    }

    void updateState() {
        numberOfStores = storeOrders.size();
        numberOfOrders = 0;
        numberOfDifferentBeverages = beverageTotals.size();
        numberOfBeverages = 0;
        for (const auto& store : storeOrders) {
            for (const auto& order : store.second) {
                numberOfOrders++;
                numberOfBeverages += order.second;
            }
        }
    }

public:
    void UpdateLimits(int numberOfStoresLimit, unordered_map<string, int> perBeverageTotalLimit) {
        limitNumberOfStores = numberOfStoresLimit;
        limitPerBeverageTotal = perBeverageTotalLimit;

        for (const auto& beverage : beverageTotals) {
            if (limitPerBeverageTotal[beverage.first] < beverage.second) {
                closeAllStores();
                return;
            }
        }

        if (numberOfStores > limitNumberOfStores) {
            closeAllStores();
            return;
        }
    }

    void OrderUpdate(int storeId, string beverageName, int quantity) {
        if (storeOrders[storeId].find(beverageName) != storeOrders[storeId].end() && quantity > 0) {
            int previousQuantity = storeOrders[storeId][beverageName];
            beverageTotals[beverageName] -= previousQuantity;
        }

        if (quantity > 0 && (numberOfStores >= limitNumberOfStores || beverageTotals[beverageName] + quantity > limitPerBeverageTotal[beverageName])) {
            cout << "reject_order: " << storeId << endl;
            return;
        }

        if (quantity == 0) {
            storeOrders[storeId].erase(beverageName);
            if (storeOrders[storeId].empty()) {
                storeOrders.erase(storeId);
            }
        } else {
            storeOrders[storeId][beverageName] = quantity;
        }

        beverageTotals[beverageName] += quantity;
        updateState();
    }

    void CloseStore(int storeId) {
        if (storeOrders.find(storeId) != storeOrders.end()) {
            for (const auto& order : storeOrders[storeId]) {
                beverageTotals[order.first] -= order.second;
            }
            storeOrders.erase(storeId);
        }
        updateState();
    }

    void PrintState() {
        cout << "number_of_stores: " << numberOfStores 
             << ", number_of_orders: " << numberOfOrders 
             << ", number_of_different_beverages: " << numberOfDifferentBeverages 
             << ", number_of_beverages: " << numberOfBeverages << endl;
    }
};

int main() {
    BeverageTracker tracker;

    // Example usage:
    tracker.UpdateLimits(5, {{"Coffee", 50}, {"Tea", 40}});
    tracker.OrderUpdate(1, "Coffee", 30);
    tracker.OrderUpdate(1, "Tea", 20);
    tracker.PrintState();

    tracker.OrderUpdate(2, "Coffee", 25); // This should be rejected
    tracker.PrintState();

    tracker.CloseStore(1);
    tracker.PrintState();

    tracker.UpdateLimits(2, {{"Coffee", 60}});
    tracker.OrderUpdate(1, "Coffee", 30);
    tracker.OrderUpdate(2, "Tea", 20);
    tracker.PrintState();

    return 0;
}

