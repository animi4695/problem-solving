#include<iostream>
#include<climits>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int a, b, x;
        cin>>a>>b>>x;
        int reqNetWorth = b-a;
        cout<<(reqNetWorth/x)<<"\n";
    }
    return 0;
}