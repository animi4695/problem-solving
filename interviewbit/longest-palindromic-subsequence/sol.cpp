#include<iostream>
#include<climits>
#include<vector>
#include<string>

using namespace std;

int solveUtil(string &A, int l, int r, vector<vector<int>>& dp){
    if(l == r) return 1;
    if(l > r) return 0;
    if(dp[l][r]) return dp[l][r];
    return dp[l][r] = A[l] == A[r] ?  2 + solveUtil(A, l+1, r-1, dp) : max(solveUtil(A, l+1, r, dp), solveUtil(A, l, r-1,dp));
}

int solve(string A) {
    int n = A.length();
    vector<vector<int>> dp(n, vector<int>(n));
    return solveUtil(A, 0, A.length()-1, dp);
}


int main(){
    return 0;
}