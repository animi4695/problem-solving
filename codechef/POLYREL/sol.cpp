#include<iostream>

using namespace std;
void solve(){
    int n;
    cin>>n;
    int y = n, c = n;
    while (y--)
    {
        int a,b;
        cin>>a>>b;
    }

    if(n <6) cout<<n<<'\n';
    else{
        while (n>=6)
        {
            n = n/2;
            c = c+n;
        }
        cout<<c<<"\n";
    }
    
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}