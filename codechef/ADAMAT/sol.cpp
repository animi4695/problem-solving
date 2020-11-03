#include<iostream>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) cin>>arr[i][j];
        }

        bool transposed = false;
        int ans = 0;
        for(int i = n-1; i > 0; i--){
            bool initially_transposed = (arr[i][0] == i+1);
            bool need_to_transpose = initially_transposed ^ transposed;
            if(need_to_transpose){
                ans++;
                transposed = !transposed;
            }
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}