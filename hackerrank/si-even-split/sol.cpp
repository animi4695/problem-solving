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
        long long n;
        cin>>n;
        if(n == 2){
            cout<<"No\n";
        }
        else{
            if(n%(long long)2 == (long long)0){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
        }
    }
    
    return 0;
}