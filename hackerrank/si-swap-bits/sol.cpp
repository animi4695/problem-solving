#include<iostream>
#include <limits>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        // Approach 
        // If I'm exchanging i and i+1 bits,
        // If i-th bit is set in the given number,  then I shall add 2 pow (i+1) to the answer and
        // If i+1 bit is set in the given number,  then I shall add 2 pow i to the answer.
        // So I shall check which bits in a given number are set and calculate accordingly using above formula.
        
        int n;
        cin>>n;
        int ans = 0;
        int i = 0;
        while(n)
        {
            if(n&1){
                ans += 1<<(i+1);
            }
            if((n>>1)&1) ans += 1<<i;
            i = i+2;
            n = n>>2;
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}