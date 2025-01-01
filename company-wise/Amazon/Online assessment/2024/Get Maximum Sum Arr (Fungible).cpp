

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;
int getMaxSumArr(vector<int> item_weights) {
    int n = item_weights.size();
    int x = n / 3; // num_of_items to remove

    // after remove x elements, we're left with 2x elements.
    int midStart = x;
    int midEnd = 2 * x - 1;

    // we need to maximize the first half and minimize the second half
    // to get maximum sum. so we need to remove smallest element from 1st half 
    // and larget elements from second half to maximize the total sum.
    priority_queue<int, vector<int>, greater<int>> leftMinQ;
    priority_queue<int> rightMaxQ;

    // 1st x elements
    for (int i = 0; i <= midStart - 1; i++) {
        leftMinQ.push(item_weights[i]);
    }

    // last x elements
    for (int i = midEnd + 1; i < item_weights.size(); i++) {
        rightMaxQ.push(item_weights[i]);
    }

    // Adjust midstart, midEnd based on conditions
    for (int i = 0; i < x; i++) {
        // whole arrays is divided in 3 equal parts.
        // leftCompare == True means smallest element in the left > starting element of middle part.
        // leftCompare == False means smallest element in the left < starting element of middle part.
        bool leftCompare = leftMinQ.top() > item_weights[midStart];

        // rightCompare == True means largest element in the right < ending element of middle part.
        // rightCompare == False means largest element in the right > ending element of middle part.
        bool rightCompare = rightMaxQ.top() < item_weights[midEnd];

        if (leftCompare && rightCompare) {
            // both the middle elements are candidates for replacing elements in the heap
            // choose one
            if(item_weights[midStart] < item_weights[midEnd])
                // moving midStart to left side will increase chances of getting max value.
                midStart++;
            else
                midEnd--;
        }
        else if(!leftCompare && rightCompare) {
            // goal: we need to remove the smallest element on left side
            // since we have a new smallest in middle, we can remove smallest element in left side 
            // and include the new smallest element in the left side from middle.
            leftMinQ.pop();
            leftMinQ.push(item_weights[midStart]);
            midStart++;
        }
        else if(leftCompare && !rightCompare) {
            // goal: we need to remove the largest element on the right side.
            // since we have a new largest in middle, we can remove curr largest element in right side.
            // and include the new largest element in the right side from middle.
            rightMaxQ.pop();
            rightMaxQ.push(item_weights[midEnd]);
            midEnd--;
        }
        else{
            int leftDiff = leftMinQ.top() - item_weights[midStart];
            int rightDiff = rightMaxQ.top() - item_weights[midEnd];
            // choose the one with larger diff. because it will maximize the total ans
            if(leftDiff < rightDiff) {
                rightMaxQ.pop();
                rightMaxQ.push(item_weights[midEnd]);
                midEnd--;
            }
            else{
                leftMinQ.pop();
                leftMinQ.push(item_weights[midStart]);
                midStart++;
            }
        }

    }

    int sum = 0;
    while(!leftMinQ.empty()){
        sum += leftMinQ.top();
        leftMinQ.pop();
    }

    while(!rightMaxQ.empty()){
        sum -= rightMaxQ.top();
        rightMaxQ.pop();
    }

    return sum;
}

int main()
{
    vector<int> item_weights = {3, 2, 1};

    cout << getMaxSumArr(item_weights);
}

// At Amazon, the team at the fulfillment center is responsible for the packaging process. There is an array, item_weights, of n items to pack. The team needs to create a new array, new_arr, by removing exactly n/3 items from item_weights without changing the order of those remaining.

// - The sum_arr of array new_arr is defined as the sum of the weights or elements in the first half of the array minus the sum of the weights in the second half of the array. - Given n items and an array item_weights, find the maximum sum_arr possible.

// Function Description

// Complete the function getMaxSumArr in the editor below.

// getMaxSumArr has the following parameters:

// int item_weights[n]: item weights
// Returns

// int: the maximum possible sum_arr

// Example 1:

// Input:  item_weights = [3, 2, 1]
// Output: 2

// Example 2:

// Input:  item_weights = [1, 3, 4, 7, 5, 2]
// Output: 4
// Explanation:

// Given n = 6, item_weights=[1, 3, 4, 7, 5, 2], remove the elements 1, 3 to leave new_arr=[4, 7, 5, 2], hence the sum will be (4+7)-(5+2) = 4.

// Constraints:
// 3 ≤ N ≤ 10^5
// -10^4 ≤ item_weights[i] ≤ 10^4
// n is divisible by 3