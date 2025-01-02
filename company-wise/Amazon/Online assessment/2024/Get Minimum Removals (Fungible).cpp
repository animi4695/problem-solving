#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

int getMinRemovals(vector<int>& data, int max_distinct) {
    unordered_map<int, int> freq;
    for (int num : data) {
        freq[num]++;
    }

    // Store frequencies in a vector
    vector<int> frequencies;
    for (auto& entry : freq) {
        frequencies.push_back(entry.second);
    }

    // Sort frequencies in ascending order
    sort(frequencies.begin(), frequencies.end());

    // Step 4: Calculate removals
    int distinct_count = freq.size();
    int removals = 0;
    int i = 0;

    // Remove elements until distinct count <= max_distinct
    while (distinct_count > max_distinct) {
        removals += frequencies[i]; // Remove elements with lowest frequency
        distinct_count--;
        i++;
    }

    return removals;
}

int main() {
    vector<int> data = {1, 2, 3, 2, 1};
    int max_distinct = 2;
    cout<<getMinRemovals(data, max_distinct) << endl;

    return 0;
}




// The data analysts of Amazon are working on a prototype service to prune the data. The service takes in an array data of n integers and an integer max_distinct. It removes some elements from the array until the final array contains at most max_distinct distinct elements.

// Given data and max_distinct, find the minimum number of elements the service must remove such that the resulting array contains at most max_distinct distinct elements.

// Function Description

// Complete the function getMinRemovals in the editor.

// getMinRemovals takes the following arguments:

// int data[n]: The data passed to the service
// int max_distinct: The maximum number of distinct elements in the final array
// Returns

// int: The minimum number of elements to be removed from the array

// Example 1:

// Input:  data = [1, 2, 3, 2, 1], max_distinct = 2
// Output: 1 
// Explanation:


  
// It is optimal to remove a single element, 3, from the array to leave [1, 2, 2, 1] that contains only 2 distinct elements. Hence the answer is 1.