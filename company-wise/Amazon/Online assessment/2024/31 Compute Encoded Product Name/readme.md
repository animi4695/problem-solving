# Task

Amazon's software team utilizes several algorithms to maintain data integrity, one of which targets the encoding of symmetrical names. Symmetrical names are unique in that they read identically in both directions, similar to palindromes in language parlance.

The chief aim of the algorithm is to rearrange the characters in the original symmetrical name according to these criteria:

The rearranged name is a reshuffled version of the original symmetrical name.
The restructured name should be symmetrical as well.
This restructured name should be lexicographically smallest among all its symmetric permutations.
Given an initial symmetrical name that contains only lowercase English characters, compute the encoded name.

A string is considered to be lexicographically smaller than the string t of the same length if the first character in s that differs from that in t is smaller. For example, "abcd" is lexicographically smaller than "abdc" but larger than "abaa".

Note that the output encoded name could match the original name if it's already the smallest lexicographically.

Function Description

Complete the function computeEncodedProductName in the editor.

computeEncodedProductName has the following parameter:

string nameString: the initial symmetrical string name.
Returns

string: the encoded nameString

Example 1:

Input:  nameString = "yxxy"
Output: "xyyx" 
Explanation:
      Rearrange the original nameString to generate "xyyx",
      which is a palindrome and also the smallest possible.
      


      
Example 2:

Input:  nameString = "ded"
Output: "ded" 
Explanation:
      The original nameString "ded" is already the smallest lexicographical palindrome possible, so it remains unchanged.
      
Constraints:
1 ≤ |nameString| ≤ 105
nameString consists of lowercase English letters only.
nameString is a palindrome.