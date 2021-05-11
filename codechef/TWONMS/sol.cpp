#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int a,b,n;
        cin>>a>>b>>n;
        if(n%2 == 1){
            a = a*2;
        }
        int res = (int)(max(a,b)/min(a,b));
        cout<<res<<"\n";
    }
    
    return 0;
}