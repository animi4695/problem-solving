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

int findFirstMultiple(int a, int b, int prime){
    for(int i = a; i <= b; i++){
        if(i%prime == 0){
            return i;
        }
    }
    return 0;
}

int main(){
    vector<int> primes = sieve();
    int t; 
    cin>>t;
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        bool p[b-a+1] = { true };
        for(int i = 0; i < (b-a+1); i++){
            p[i] = true;
        }

        if(a == 1){
            p[0] = false;
        }

        for(int i = 0 ; (primes[i])*(primes[i]) <= b; i++){
            int x = findFirstMultiple(a, b, primes[i]);
            if(x == primes[i]){
                x = x+primes[i];
            }
            for(int j = x ; j <= b; j = j + primes[i]){
                if(p[j-a] == true)  p[j-a] = false;
            }
        }

        for(int i = 0 ; i < (b-a+1); i++){
            if(p[i]) cout<<i+a<<"\n";
        }

        cout<<"\n";
    }
    
    
    return 0;
}