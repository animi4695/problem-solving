#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int solve(int n){
    int ans = 0;
    for(int i = 1; i <= sqrt(n); i++){
        if(n%i == 0){
            if(n/i == i) ans++;
            else{
                ans += 2;
            }
        }
    }

    return ans;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        cout<<solve(n)<<"\n";
    }
    
    return 0;
}