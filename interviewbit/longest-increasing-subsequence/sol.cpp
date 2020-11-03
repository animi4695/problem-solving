#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int lis(const vector<int> &A) {
    // dp state -> length of longest increasing subsequence till i including i
    int n = A.size();
    if(n == 0) return 0;
    vector<int> dp(n);
    int res = 1;
    for(int i = 0; i < n; i++){
        int maxVal = 0;
        for(int j = 0 ; j < i; j++){
            if(A[j] < A[i]){
                maxVal = max(maxVal, dp[j]);
            }
        }
        dp[i] = maxVal + 1;
        res = max(res, dp[i]);
    }
    return res;
}


int main(){
    return 0;
}