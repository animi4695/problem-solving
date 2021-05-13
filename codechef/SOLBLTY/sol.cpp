#include<iostream>
#include<climits>
#include<cmath>

using namespace std;
long long solve(int x, int a, int b){
    return (a + (100 - x)*b)*10;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,a,b;
        cin>>x>>a>>b;   
        cout<<solve(x,a,b)<<"\n";
    }
    return 0;
}