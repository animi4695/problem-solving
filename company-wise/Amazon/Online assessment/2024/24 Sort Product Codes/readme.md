# Task

Sort Product Codes
INTERN
Amazon has millions of products sold on its e-commerce website, and each product is identified by its product code.

Given an array of n productCodes and order , a string that represents the precedence of characters, sort the productCodes in lexicographically increasing order per the precedence.

Note: Lexicographical order is defined in the following way. When we compare strings s and t , first we find the leftmost position with different characters: s[0] and t[0] . If there is no such position (i.e. s is a prefix of t or vice versa), then the shorter string is prior to the longer one. Otherwise, we compare characters s[i] and t[i] according to their order in the given precedence order.


Function Description

Complete the function sortProductCodes in the editor below. sortProductCodes has the following parameter(s):

string order : the new precedence order string
productCodes[n] : the array to sort

Returns

string[n] : the productCodes array in sorted order


Example 1 :

Input: order = "abcdefghijklmnopqrstuvwxyz", productCodes = ["adc", "abc"]
Output: ["abc", "adc"]
Explanation: Consider the strings "adc" and "abc", the first point of difference is at position 1 (assuming start index is 0), and 'd'>'b' according to the given precedence order.


Constraints:
1 ≤ n ≤ 5000
1 ≤ length(productCodes[i]) ≤ 100
length(order) = 26
order and all productCodes[i] contain lowercase English letters only.
