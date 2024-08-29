/*

The TikTok team is analyzing clips to measure their unique content strength. Given a string clip of length n consisting of only lowercase English characters, imagine the clip is circular, meaning after the n-th character, the sequence continues from the 1st character again.

Circular Nature: Since the clip is circular, you can form substrings that wrap around from the end of the string back to the beginning. For instance, with the string "yxz", valid substrings include "y","x","z","yx","xz","zy","yxz","xzy" and "zyx".

The "content strength" of a circular clip is determined by the number of unique substrings that consist of only consonants. Your task is to find the content strength of this circular clip.

Function Description

Complete the function calculateContentStrength in the editor.

calculateContentStrength has the following parameter:

string clip: the circular clip whose content strength has to be determined.
Returns

int: the content strength of the circular clip

Example 1:

Input:  clip = "bac"
Output: 3 
Explanation:


The different possible substrings of the circular clip are: ["b", "a", "c", "ba", "ac", "cb", "bac", "acb", "cba"].

The substrings that consist of only consonants are: ["b", "c", "cb"].

*/


#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
#include<queue>

using namespace std;
bool isConsonent(char c) {
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int calculateContentStrength(string clip) {
    int n = clip.length();
    string input = clip + clip;

    unordered_set<string> res_set;

    for(int i = 0; i < n; i++) {
        string substring = "";
        for(int j = i; j < i + n; j++) {
            if(isConsonent(input[j])){
                substring += input[j];
                res_set.insert(substring);
            }
            else{
                break;
            }
        }
    }

    return res_set.size();
}

int main() {
    string clip = "bac";
    cout<<calculateContentStrength(clip)<<"\n";
}