#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;

long long solve(long long n){
    long long ans = 0;
    long long temp = 0;
    while(n){
        if(n&1 == true){
            temp++;
        }
        else{
            ans = max(ans, temp);
            temp = 0;
        }
        n = n>>1;
    }
    ans = max(ans, temp);
    return ans;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        cout<<solve(n)<<"\n";
    }
    
    return 0;
}