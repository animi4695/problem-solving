// Given a string, check if it is valid (return 1 :) or not (return 0 :). A valid string must:

// Be divisible by 3 (interpreted as the numeric value of the string is divisible by 3).
// Contain the digit '7' at least twice.
// Example 1:

// Input:  s = "771"
// Output: 1 
    
// Example 2:

// Input:  s = "777"
// Output: 1 
      
// Example 3:

// Input:  s = "123777"
// Output: 1 
      
// Example 4:

// Input:  s = "12345"
// Output: 0 
      
// Example 5:

// Input:  s = "71"
// Output: 0 
      
// Example 6:

// Input:  s = "171"
// Output: 0 
      
// Example 7:

// Input:  s = "70"
// Output: 0 

#include<iostream>
#include<string>

using namespace std;

int isValidString(string s){
    int num = stoi(s);
    int cnt = 0;
    if(num % 3 == 0)
        // check if digit 7 contains twice
        for(auto ch : s) {
            if(ch == '7')
                cnt++;
        }
        if(cnt == 2)
            return 1;
    return 0;
}

int main(){
    cout<<isValidString("771")<<"\n";
    cout<<isValidString("123456")<<"\n";
    cout<<isValidString("71")<<"\n";
    return 0;
}
