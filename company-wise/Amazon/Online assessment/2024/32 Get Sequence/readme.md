# Task

Data scientists at Amazon are working on a utility for genome sequencing algorithms. The utility finds anagram patterns in a pair of DNA sequence strings. A pair of DNA is special if they are anagrams after removing any number of occurrences of at most one character from each DNA sequence.

Given n pairs of DNA, for each pair, attempt to make them anagrams. Return a list of boolean values, one for each pair, where True means a pair is special.

Function Description

Complete the function getSequence in the editor below.

getSequence has the following parameter(s):

String dna[n][2]: the pairs of DNA sequences.
Returns

boolean[n]: 'true' if the pair is special, and 'false' otherwise

Example 1:

Input:  dna = [["safddadfs", "famafmss"]]
Output: [true] 
Explanation:

The strings are anagrams after removing all the occurrences of character 'd' from s and character 'm' from t. Return [True].
   
Note: It is not required that all instances of a character be removed. For example, given 'aab' and 'ba', one 'a' can be removed from 'aab' to leave 'ab'.

      
Example 2:

Input:  dna = [["abcee", "acdeedb"], ["sljffsajej", "sljsje"]]
Output: [true, false] 
Explanation:

      For pair 1, remove 'b' from the second string and leave the first string untouched.

      For pair 2, dna1 contains 'f' and 'a' which are not in dna2. They cannot be anagrams after removing only a character from dna1.

      
Constraints:
1 <= n <= 10
1 <= length of dna[i][0], dna[i][1] <= 10000.
The strings in dna1 and dna2 consist of lowercase English letters only.