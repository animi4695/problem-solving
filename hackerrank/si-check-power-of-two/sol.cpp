#include<iostream>
#include <limits>
#include<cmath>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        
        // APPROACH - 1
        // if(ceil(log2(n)) == floor(log2(n))) cout<<"True\n";
        // else
        // {
        //     cout<<"False\n";
        // }

        // APPROACH -2
        // count set bits. for powers of 2, set bits count is only 1
        int count = 0;
        while (n!=0)
        {
            count += n&1;
            n = n>>1;
        }
        
        if(count == 1) cout<<"True\n";
        else cout<<"False\n";
    }
    
    return 0;
}