Task:

As part of your Day 1 orientation, your new team is hosting a programming challenge.

You haven been asked to participate in completing the following task.

Given an array of integers, perform operations to satisfy the following constraints:

The first array element must be 1.
For all other elements, the difference between adjacent integers must not be greater than 1 . In other words, for 1 ≤ i < n , arr[i] - arr[i-1] ≤ 1 .
To accomplish this, the following operations are available:

Rearrange the elements in any way.
Reduce any element to any number that is at least 1.
Determine the maximum value that can be achieved for the final element of the array by following these operations and constraints.

Function Description

Complete the function maximumFinal in the editor.

maximumFinal has the following parameter:

int arr[] : an array of integers

Returns

int : the maximum final value of the last element

Example 1 :

Input: arr = [3, 1, 3, 4]
Output: 4
Explanation: Here's how the maximum final value can be achieved:

Subtract 1 from the first element, making the array [2, 1, 3, 4].
Rearrange the array into [1, 2, 3, 4].
The final element's value is 4, the maximum value that can be achieved.
Therefore, the answer is 4.

Constraints:
1 <= n <= 105
1 <= arr[i] <= 109