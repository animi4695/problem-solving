#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;



int findPasswordStrength(string password) {
    // record the last occurrence index of char
    unordered_map<char, int> lastCharIndex;

    int n = password.size();
    int res = 0;

    for (int i = 0; i < n; ++i) {
        char c = password[i];

        int leftIndex = 0;
        int rightIndex = n - 1;

        if (lastCharIndex.find(c) != lastCharIndex.end()) {
            leftIndex = lastCharIndex[c] + 1;
        }

        res += (i - leftIndex + 1)* (rightIndex - i + 1);

        lastCharIndex[c] = i;
    }

    return res;
}

int main() {
    
    cout<<findPasswordStrength("good");
    return 0;
}


// Find the password strength for a given password. For example, if the password is "good", then iterate over all substrings and find the distinct character counts:

// g = 1,
// o = 1,
// o = 1,
// d = 1,
// go = 2,
// oo = 1,
// od = 2,
// goo = 2,
// ood = 2,
// good = 3
// At the end, add all the distinct character counts to determine the password strength. In this case, the password strength is 16.

// Function Description

// Complete the function findPasswordStrength in the editor.

// findPasswordStrength has the following parameter:

// String password: the password string
// Returns

// int: the password strength

// Example 1:

// Input:  password = "good"
// Output: 16 
// Explanation:


// Iterate over all substrings and find the distinct character counts:

      

        
// g = 1,

        
// o = 1,

        
// o = 1,

        
// d = 1,

        
// go = 2,

        
// oo = 1,

        
// od = 2,

        
// goo = 2,

        
// ood = 2,

        
// good = 3

      


// The total strength is the sum of all distinct character counts: 1 + 1 + 1 + 1 + 2 + 1 + 2 + 2 + 2 + 3 = 16.











// Find the password strength for a given password. For example, if the password is "good", then iterate over all substrings and find the distinct character counts:

// g = 1,
// o = 1,
// o = 1,
// d = 1,
// go = 2,
// oo = 1,
// od = 2,
// goo = 2,
// ood = 2,
// good = 3
// At the end, add all the distinct character counts to determine the password strength. In this case, the password strength is 16.

// Function Description

// Complete the function findPasswordStrength in the editor.

// findPasswordStrength has the following parameter:

// String password: the password string
// Returns

// int: the password strength

// Example 1:

// Input:  password = "good"
// Output: 16 
// Explanation:


// Iterate over all substrings and find the distinct character counts:

      

        
// g = 1,

        
// o = 1,

        
// o = 1,

        
// d = 1,

        
// go = 2,

        
// oo = 1,

        
// od = 2,

        
// goo = 2,

        
// ood = 2,

        
// good = 3

      


// The total strength is the sum of all distinct character counts: 1 + 1 + 1 + 1 + 2 + 1 + 2 + 2 + 2 + 3 = 16.