#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
int solve(vector<vector<int>> A, int n, int m){
    // dp state -> max num of apples you can collect from source to cell(i,j)
    int dp[n+1][m+1];
    
    // base condition
    dp[0][0] = A[0][0];
    for(int i = 1; i <= n; i++){
        dp[i][0] = dp[i-1][0] + A[i][0];
    }

    for(int j = 1; j <= m; j++){
        dp[0][j] = dp[0][j-1] + A[0][j];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = A[i][j] + max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> A(n+1, vector<int>(m+1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>A[i][j];
            }
        }

        cout<<solve(A, n, m)<<"\n";
    }
    
    return 0;
}