#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int getStablePeriodsCount(vector<int>& revenues, int k) {
    int n = revenues.size();

    int MOD = 1e9 + 7;
    int left = 0, right = 0;

    int count = 0;

    unordered_map<int, int> freq;

    while(right < n) {
        freq[revenues[right]]++;

        while(freq.size() > k){
            freq[revenues[left]]--;
            if(freq[revenues[left]] == 0)
                freq.erase(revenues[left]);
            left++;
        }
        count = (count + (right - left + 1)) % MOD;

        right ++;
    }

    return count;
}

int main() {
    vector<int> revenues = {1, 2, 1};
    int k = 1;

    cout<<getStablePeriodsCount(revenues, k);
}












// Amazon developers are building a prototype for a regex generator for the given strings.

// For the prototype version, the regex consists of uppercase English letters, '[' and ']'. Here, a string of characters enclosed in square brackets '[' and ']' matches any of the one characters in that string. Also, the string of characters enclosed within '[' and ']' consists of uppercase English letters only with no repetition.

// For example:

// "[ABBR]ABC" is not a valid regex as B occurs twice between square brackets.
// "[]ABC", "A[A][", "][" and "]ABC" are also not valid regexes as brackets must contain some string, and brackets should also form a balanced bracket sequence.
// "[ABC]BC[A]" is a valid regex and matches with "BBCA" and "ABCA", but not with "ABBCA".
// "[ABCZ][Q]" is a valid regex and matches with "AQ", "BQ", "CQ", "ZQ" but not with "DQ" or "ZC".
// "[A][B][C][D]" is a valid regex and matches only with the string "ABCD".
// Given 3 strings x, y, and z of length n, find the longest regex that matches both the strings x and y but does not match with the string z. If no such regex exists output -1. If multiple such regexes exist output the lexicographically smallest one.


// Note:

// The length of a regex is the number of characters in it, i.e., including uppercase English alphabets, '[' and ']'.
// A string p is lexicographically smaller than string q, if p is a prefix of q, is not equal to q, or there exists i such that p_i < q_i and for all j < i, it is satisfied that p_j = q_j. Note that while comparing p_j and q_j, we consider their ASCII values, i.e., '[' and ']' are greater than any uppercase English letters. For example, "ABC" is lexicographically smaller than "BCD" and "ABCDE" but larger than "AAC" and "AACDE".
// The answer string, which is to be returned can turn out to be in the order of 10^6 for larger n's.
// Function Description

// Complete the function findLongestRegex in the editor.

// findLongestRegex has the following parameters:

// x: a string :)
// y: a string :O
// z: a string :3
// Returns

// string: the longest lexicographically smallest regex matching x and y but not z, if no such regex exists return -1 as a string.

// Example 1:

// Input:  x = "AB", y = "BD", z = "CD"
// Output: "[ABCDEFGHJKLMNOPQRSTUVWXYZ][ABCDEFGHJKLMNOPQRSTUVWXYZ]" 
// Explanation:

    
// Regex "[ABCDEFGHJKLMNOPQRSTUVWXYZ][ABCDEFGHJKLMNOPQRSTUVWXYZ]" matches with strings "AB" and "BD", but not with string "CD".

      
// Example 2:

// Input:  x = "AERB", y = "ATRC", z = "AGCB"
// Output: "[ABCDEFGHJKLMNOPQRSTUVWXYZ][ABCDEFGHJKLMNOPQRSTUVWXYZ][ABCDEFGHJKLMNOPQRSTUVWXYZ][ABCDEFGHJKLMNOPQRSTUVWXYZ][ABCDEFGHJKLMNOPQRSTUVWXYZ][ABCDEFGHJKLMNOPQRSTUVWXYZ][ABCDEFGHJKLMNOPQRSTUVWXYZ][ABCDEFGHJKLMNOPQRSTUVWXYZ]" 
// Explanation:

    
// Regex "[ABCDEFGHJKLMNOPQRSTUVWXYZ][ABCDEFGHJKLMNOPQRSTUVWXYZ][ABCDEFGHJKLMNOPQRSTUVWXYZ][ABCDEFGHJKLMNOPQRSTUVWXYZ][ABCDEFGHJKLMNOPQRSTUVWXYZ][ABCDEFGHJKLMNOPQRSTUVWXYZ][ABCDEFGHJKLMNOPQRSTUVWXYZ][ABCDEFGHJKLMNOPQRSTUVWXYZ]" matches with strings "AERB" and "ATRC", but not with string "AGCB"