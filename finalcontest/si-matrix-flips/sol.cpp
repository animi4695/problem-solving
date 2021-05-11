#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, m;
        cin>>n>>m;
        bool mat[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }

        cout<<solve(mat, n, m)<<"\n";
    }
    
    return 0;
}