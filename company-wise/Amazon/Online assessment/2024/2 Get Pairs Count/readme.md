# Task

Developers in your team are building a multi-process analysis tool to analyze the computational intensity of the processes. There are n processes and the ith process needs process[i] computation resources for completion.

Two processes are considered to be computationally the same if their resource requirements differ by at most k .

Given the array process and an integer k , find the number of pairs of processes that are computationally the same.

Function Description

Complete the function getPairsCount in the editor.

getPairsCount takes the following arguments:

int process[n] : the computational resource requirement of the processes
int k : the threshold for being computationally the same

Returns

long integer : the number of pairs of processes that are computationally the same

Examples and Constrains...

Example 1 :

Input: process = [100, 200, 300, 400], k = 250
Output: 5
Explanation: The computationally-same processes are (100, 200), (100, 300), (200, 300), (200, 400), and (300, 400).

Example 2 :

Input: process = [10, 12, 11], k = 0
Output: 0
Explanation: All the pairs of processes have differences between computational resource requirements greater than 0.

Example 3 :

Input: process = [7, 10, 13, 11], k = 3
Output: 4
Explanation: The process pairs are shown in the above image. Hence the answer is 4.

Constraints:
1 ≤ n ≤ 2 * 105
1 ≤ process[i] ≤ 106
0 ≤ k ≤ 106
