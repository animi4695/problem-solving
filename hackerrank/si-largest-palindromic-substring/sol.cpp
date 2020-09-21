#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
bool checkPalin(char str[],int n, int i, int j){
    int p1 = i, p2 = j;
    while(p2 >= i && p1 <= j){
        if(str[p1] != str[p2]) return false;
        p2--;
        p1++;
    }
    return true;
}

int solve(char str[], int n){
    // bruteforce
    // Idea -> Generate all substring and check each substr is a palindrome, It found, save it and look for larger palindrome
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(checkPalin(str,n, i, j)){
                ans = max(ans, j-i+1);
            }
        }
    }
    return ans;
}


int solve1(char str[], int n){
    // bit optimized
    // Idea -> Take each index of the string , treat it as a center of the palindrome
    //         and compare its left and right chars for equality. If they are equal,store it keep moving.. else skip.
    int ans = 1;
    int p1, p2;
    // one by one, consider every char as palindrome center
    for(int i = 1; i < n; i++){
        // find longest even length palindome string.
        p1 = i-1;
        p2 = i;
        while(p1 >= 0 && p2 < n && str[p1] == str[p2]){
            if(p2-p1+1 > ans) ans = p2-p1+1;
            p1--;
            p2++;
        }

        // find the longest odd length palindrome string.
        p1 = i-1;
        p2 = i+1;
        while(p1 >= 0 && p2 < n && str[p1] == str[p2]){
            if(p2-p1+1 > ans) ans = p2-p1+1;
            p1--;
            p2++;
        }
    }

    return ans;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        char str[n];
        for(int i = 0; i < n; i++) cin>>str[i];
        cout<<solve1(str, n)<<"\n";
    }
    
    return 0;
}