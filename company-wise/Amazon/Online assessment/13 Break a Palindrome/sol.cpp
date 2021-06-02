#include<iostream>
#include<unordered_map>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

string breakPalindrome(string palindrome) {
    // go till center of the string and try to make it lexicographically non-palindrome
    if(palindrome.length() == 1)        
        return "";
    for(int i = 0; i < palindrome.length()/2; i++){
        if(palindrome[i] != 'a'){
            palindrome[i] = 'a';
            return palindrome;
        }
    }
    palindrome[palindrome.length()-1] = 'b';
    return palindrome;
}

int main() {
    string ip = "aba";
    cout<<breakPalindrome(ip);
}

