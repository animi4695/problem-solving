#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
long long solve(string n, long long p){
    // Idea -> xy%a = (x%a)*(y%a)
    long long ans = 0;
    for(int i = 0 ; i < n.length(); i++){
        ans = (ans*10 + (int)n[i] - '0')%p;
    }

    return ans;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string n;
        long long p;
        cin>>n>>p;
        cout<<solve(n,p)<<"\n";
    }
    
    return 0;
}