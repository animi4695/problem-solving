#include<iostream>
#include<climits>
#include<vector>
#include<unordered_set>
#include<set>
#include<algorithm>

#define MOD 1000000007

using namespace std;

int solve(vector<vector<int>> & dp, int n, int m){
    // dp state : Num. of ways to reach cell(i,j) from the source
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(dp[i][j] != -1){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1] + dp[i][j-1])%MOD;
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    return dp[0][0] == 0 ? 0 : dp[n-1][m-1];
}

void baseCondition(vector<vector<int>> & dp, vector<vector<int>> blocked, int n, int m){
    for(auto block : blocked){
        dp[block[0]][block[1]] = -1;
    }

    int i;
    for(i = 0; i < n; i++){
        if(dp[i][0] != -1){
            dp[i][0] = 1;
        }
        else{
            break;
        }
    }

    for(; i<n; i++){
        dp[i][0] = 0;
    }

    int j;
    for(j = 0; j < n; j++){
        if(dp[0][j] != -1){
            dp[0][j] = 1;
        }
        else{
            break;
        }
    }

    for(; j<n; j++){
        dp[0][j] = 0;
    }
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, m, b;
        cin>>n>>m>>b;
        vector<vector<int>> blocked(b, vector<int>(2));
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i = 0; i < b; i++){
            int i, j;
            cin>>i>>j;
            dp[i][j] = -1;
        }

        for(int i = 0; i < n; i++){
            if(dp[i][0] != -1) dp[i][0] = 1;
            else{
                while(i < n) dp[i++][0] = 0;
            }
        }

        for(int j = 1; j < m; j++){
            if(dp[0][j] != -1) dp[0][j] = 1;
            else{
                while(j < m) dp[0][j] = 0;
            }
        }

        cout<<solve(dp, n, m)<<"\n";

    }
    
    return 0;
}