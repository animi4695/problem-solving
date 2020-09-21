#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
bool solve(int n){
    // x = b^y is the same as y = logb(x)
    // eg -> 1000 = 10^3 i.e 3 = log10(1000) which in-turn equals log2(1000)/log2(10);

    for(int i =2; i <= sqrt(n); i++){
        float y = log2(n)/log2(i);
        if(ceil(y) == floor(y)) return true;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        if(solve(n)) cout<<"Yes\n";
        else cout<<"No\n";
    }
    
    return 0;
}