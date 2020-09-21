#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
long long onesCompliment(long long n){
    int bit_count = floor(log2(n))+1;
    int ones = ((1 << bit_count) - 1);
    return ones ^ n;
}
long long solve(long long n){
    long long threshold = onesCompliment(n);
    long long count = 0;
    for(int i = 1; i <= threshold; i++){
        if((n+i) == (n^i)){
            count++;
        }
    }

    return count;
}

long long solve1(long long n){
    // count 0 bits
    long long count = 0;
    while(n > 0){
        count += (n&1) == 0 ? 1 : 0;
        n = n>>1;
    }
    return ((long long)1 << count)-1;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        cout<<solve1(n)<<"\n";
    }
    
    return 0;
}