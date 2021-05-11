#include<iostream>
#include<climits>
#include<cmath>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, s;
        cin>>m>>s;
        if(m < s){
            cout<<0<<"\n";
        }
        else if(m == s){
            cout<<1<<"\n";
        }
        else{
            cout<<floor(m/s)<<"\n";
        }
    }
    return 0;
}