#include<iostream>
#include <limits>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int a,b;
        cin>>a>>b;

        int a_xor_b = a^b;
        int count = 0;
        while (a_xor_b)
        {
            count += (a_xor_b & 1);
            a_xor_b = a_xor_b>>1;
        }
        cout<<count<<"\n";
    }
    
    return 0;
}