#include<iostream>

using namespace std;
string solve(int n, int k, int x, int y){
    if(x == y) return "YES";
    int m = x;
    x = (x+k)%n;
    while (x != m)
    {
        if(x == y) return "YES";
        x = (x+k)%n;
    }
    return "NO";
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, k, x, y;
        cin>>n>>k>>x>>y;
        cout<<solve(n,k,x,y)<<"\n";
    }
    
    return 0;
}