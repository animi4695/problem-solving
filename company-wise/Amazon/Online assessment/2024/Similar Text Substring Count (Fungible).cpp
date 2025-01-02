#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

bool isSimilar(string key, string sub){
    vector<int> mismatches;
    for(int i = 0; i < key.length(); i++){
        if(key[i] != sub[i]) {
            mismatches.push_back(i);
        }
    }

    if(mismatches.size() == 0)
        return true;
    if(mismatches.size() != 2)
        return false;
    
    return (mismatches[0] + 1 == mismatches[1] &&
            key[mismatches[0]] == sub[mismatches[1]] &&
                key[mismatches[1]] == sub[mismatches[0]]);
}

int countSimilarSubstrings(string key, string text) {
    int keyLen = key.size();
    int textLen = text.size();

    int count = 0;
    for(int i = 0; i <= textLen; i++) {
        string sub = text.substr(i, keyLen);
        if(isSimilar(key, sub))
            count++;
    }
    return count;
}

int main() {
    string key = "moon";
    string text = "monomon";

    cout<<countSimilarSubstrings(key, text);
    return 0;
}





// Amazon shoppers often refer to user reviews to help them decide whether to purchase an item. They can focus their efforts using a keyword search, but typographical errors are common in reviews. To help mitigate this problem, Amazon's algorithm will include reviews that contain a word that is similar to the search term. A string, s, is similar to another string, t, if it is possible to swap two adjacent characters at most once in s to turn it into t. Given a keyword string named keyword, find how many substrings of review are similar to keyword.

// Note: A substring is a contiguous sequence of characters within a string. Two substrings are considered distinct if they begin at different positions.

// Example 1:

// Input:  key = "moon", text = "monomon"
// Output: 2 
// Explanation:


// Consider the first four characters in text, i.e "mono". Swap the last two characters to match the keyword "moon".

// The last four characters in the text are "onom". Swap the first two characters to match the keyword.

// Thus, there are 2 substrings of "monom" that are similar to "moon". Note, that no other substring is similar to the given key.
  
      
// Example 2:

// Input:  key = "aaa", text = "aaaa"
// Output: 2 
// Explanation:


// There are 2 substrings of "aaaa" that are similar to "aaa" are:

// aaaa

// aaaa
 
      
// Constraints:
// key and text will consist solely of lowercase English letters.
// 1 ≤ |key| ≤ |text| ≤ 50, where |s| denotes the length of a string s.