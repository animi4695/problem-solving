#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int minRange(int i, int n, int m, vector<int>& A, vector<int>& B, vector<vector<int>>& dp);

int main() {
    int n = 5;
    int m = 2;
    vector<int> A = {1,2, 17, 16, 9};
    vector<int> B = {3,4,5,6,11};

    vector<vector<int>> dp(n + 1, vector<int>(m, -1));
    int res = minRange(0, n, m, A, B, dp);

    cout<<res;

    return 0;
}

int minRange(int i, int n, int m, vector<int>& A, vector<int>& B, vector<vector<int>>& dp){
    if(m == 0){
        // we are out of flips
        int currMax = -1;
        int currMin = INT_MAX;
        for(int i = 0; i < n; i++){
            currMax = max(A[i], currMax);
            currMin = min(A[i], currMin);
        }
        return abs(currMax - currMin);
    }
    if(i >= n)
        return INT_MAX;
    if(dp[i][m] != -1){
        return dp[i][m];
    }
    // we have 2 options, 
    // don't flip current index.
    int res = minRange(i+1, n, m, A, B, dp);
    // flip the curr index;
    int temp = A[i];
    A[i] = B[i];
    res = min(res, minRange(i+1, n, m - 1, A, B, dp));
    // reset flipped element i.e set back to original state
    A[i] = temp;
    
    dp[i][m] = res;
    return res;
}