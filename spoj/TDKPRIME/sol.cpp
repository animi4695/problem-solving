#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> sieve(){
    int n = 100000000;
    vector<bool> ar(n+1, true);
    vector<int> primes;
    ar[0] = false;
    ar[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(ar[i] == true){
            // if a number is prime, mark all multiples of it as false;
            for(int j = i*i; j <= n; j = j+i){
                if(ar[j] == true) ar[j] = false;
            }
        }
    }

    for(int i = 0; i < ar.size(); i++){
        if(ar[i] == true) primes.emplace_back(i);
    }
    return primes;
}

int main(){
    vector<int> primes = sieve();
    int q;
    cin>>q;
    while (q--)
    {
        int k;
        cin>>k;
        cout<<primes[k-1]<<"\n"; 
    }
    
    return 0;
}