# Task

AWS provides scalable system. A set of n servers are used for horizontally scaling an application.

The goal is to have the computational power of the servers in non-decreasing order. To do so, you can increase the computational power of each server in any contiguous segment by x. Choose the values of x such that after the computational powers are in non-decreasing order , the sum of the x values is minimum.


Example 1 :

Input: power = [3, 4, 1, 6, 2]
Output: 7
Explanation: Add 3 units to the subarray [2, 4] and 4 units to the subarray [4, 4,]. The final arrangement of the server is: [3, 4, 4, 9, 9]. The ans is 3 + 4 = 7. (As shown in the image)

Note - Not sure if this answer is correct, we can also get the answer in another way.
[3,4,1,6,2] Add 3 to 1
[3,4,4,6,2] Add 4 to 2
[3,4,4,6,6] Total = 3+4 = 7


Constraints:
1 <= n <= 105
1 <= power[i] <= 109