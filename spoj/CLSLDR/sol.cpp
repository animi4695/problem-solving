#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
int dp[1001][1001];

int solve(int n, int o)
{
	if(n==1) return 1;
	else 
	{
		dp[n][o] = (solve(n-1,o)+o-1)%n+1;
		return dp[n][o];
	}
}

void precomp(){
    for(int i = 1; i <= 1000; i++){
        dp[1][i] = 1;
        solve(1000, i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    precomp();
    int t;
    cin>>t;
    while (t--)
    {
        int n, m, o;
        cin>>n>>m>>o;
        cout<<(m+dp[n][o]-1)%(n) +1<<"\n";
    }
    
    return 0;
}