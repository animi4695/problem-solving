#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
long long trailingzeroes(long long n){
    long long countZeroes = 0;
    if(n < 5){
        return 0;
    }
    else{
        for(int i = 5; n/i > 0; i= i*5){
            countZeroes += n/i;
        }
    }

    return countZeroes;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        long long n;
        cin>>n;
        cout<<trailingzeroes(n)<<"\n";
    }
    
    return 0;
}