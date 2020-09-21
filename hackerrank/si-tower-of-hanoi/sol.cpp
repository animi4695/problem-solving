#include<iostream>
#include <limits>

using namespace std;
void toh(int n, char src, char dest, char temp){

    //base condition
    if(n == 0) return;

    toh(n-1, src, temp, dest);
    cout<<"Move "<<n<<" from "<<src<<" to "<<dest<<"\n";
    toh(n-1, temp, dest, src);
}

int main(){
    // TC - O(T*2^N)
    // SC - O(2^N)
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        // total 2^n steps
        int count = (1<<n) - 1;
        cout<<count<<"\n";
        toh(n, 'A', 'C', 'B');
        
    }
    
    return 0;
}