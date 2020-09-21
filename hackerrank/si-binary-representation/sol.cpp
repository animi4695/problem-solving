#include<iostream>
#include <limits>
#include<vector>
#include<algorithm>

using namespace std;
void solve(int n){
    if(n>1){
        solve(n>>1);
    }

    cout<<(n&1);
}
int main(){
    int t;
    cin>>t;
    string res;
    while (t--)
    {
        int n;
        cin>>n;
        solve(n);
        cout<<"\n";
    }
    
    return 0;
}