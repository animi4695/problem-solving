#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits> // For INT_MIN
using namespace std;

vector<int> createArrayGeneratorService(vector<int>& arr, string state, int m) {
    vector<int> result;
    int n = arr.size();
    vector<char> stateArray(state.begin(), state.end()); // Convert string to char array

    for (int operation = 0; operation < m; operation++) {
        // Find the largest available element
        int maxAvailable = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (stateArray[i] == '1') {
                maxAvailable = max(maxAvailable, arr[i]);
            }
        }

        // Append the largest available element to result
        result.push_back(maxAvailable);

        // Update the state array
        vector<int> list_idx;
        for (int i = 1; i < n; i++) {
            if (stateArray[i] == '0' && stateArray[i - 1] == '1') {
                list_idx.push_back(i);
            }
        }
        for (int idx : list_idx) {
            stateArray[idx] = '1';
        }
    }

    return result;
}

int main() {
    int m = 5;
    vector<int> arr = {5, 3, 4, 6};
    string state = "1100";

    vector<int> result = createArrayGeneratorService(arr, state, m);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}


// Your project team needs to work closely with a group of software testers. They have requested that your team create an array generator service to assist with testing software functionality. Create an array generator service.

// Its input parameters are:

// arr[n] contains n positive integers.
// state is a string that contains n characters.
// Each character is a '0' or '1'.
// If state[i] = '1', arr[i] is available.
// If state[i] = '0', arr[i] is blocked.
// To create an integer array, S, the following operation is performed exactly m times. S is initially empty.

// Choose any arr[i] that is available, that is, where state[i] = '1', the same element can be chosen any number of times.
// Append the value in arr[i] to S.
// For all state[i] = '0' such that state[i-1] = '1', change state[i] to '1'. For example, if state = '0100101' before the operation, it equals '0110111' after the operation.
// Find the lexicographically largest sequence S that can be obtained after m operations.

// Note: A sequence x of length m is lexicographically larger than sequence y of length m if there exists such i (0 ≤ i < m), that x[i] > y[i], and for any j (0 ≤ j < i) x[j] = y[j].

// Input:  arr = [5, 3, 4, 6], state = "1100", m = 5
// Output: [5, 5, 6, 6, 6] 
