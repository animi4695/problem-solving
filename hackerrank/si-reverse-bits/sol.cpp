#include<iostream>
#include <limits>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int N;
        cin>>N;
        unsigned int res = 0;
        int power = 31;
        while(N){
            res += (N&1)<<power;
            N = N>>1;
            power--;
        }

        cout<<res<<"\n";

    }
    
    return 0;
}