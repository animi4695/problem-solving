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
        int n;
        cin>>n;
        vector<int> even, odd;
        for(int i = 0; i < n; i++){
            int a;
            cin>>a;
            if(a%2 == 0)
                even.push_back(a);
            else
                odd.push_back(a);
        }

        for(auto e : even)
            cout<<e<<" ";
        for(auto o : odd)
            cout<<o<<" ";
        cout<<"\n";
    }
    return 0;
}