#include<iostream>
#include<climits>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
int solve(int D, int d, int a, int b, int c) {
    int calChefDistance = d*D;
    if(calChefDistance >= 42)
        return c;
    else if(calChefDistance >= 21 && calChefDistance < 42)
        return b;
    else if(calChefDistance >= 10 && calChefDistance < 21)
        return a;
    else 
        return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int D, d, a, b, c;
        cin>>D>>d>>a>>b>>c;
        cout<<solve(D, d, a, b, c)<<"\n";
    }
    return 0;
}