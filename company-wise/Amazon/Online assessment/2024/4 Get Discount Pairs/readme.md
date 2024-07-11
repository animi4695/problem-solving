# Task

Your favorite online store is offering a discount on every purchase of a pair of products whose price sum is divisible by x. Given the price of n products in the store, find the number of pairs (i, j) where i < j and prices[i] + prices[j] is divisible by x.


Function Description

Complete the function getDiscountPairs in the editor.

getDiscountPairs has the following parameter(s):

1. int x : sum of a pair of integers should be divisible by this number
2. int prices[n] : the prices of the products

Returns

int : the number of pairs in the array whose sum is divisible by x


Example...
Constraints...

Example 1 :

Input: x = 60, prices = [31, 25, 85, 29, 35]
Output: 3
Explanation: The answer is 3 based on the pairs (31, 29), (25, 35), and (85, 35). Each pair sums to a number divisible by x.

Constraints:

1 ≤ x ≤ 2 * 109

1 ≤ n ≤ 105

1 ≤ prices[i] ≤ 109