#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
int mod = 1e9+7;
int prime = 101;
vector<long long> powers(10002, 0);

void precomputePowers(){
    powers[0] = 1;
    for(int i = 1; i < 10002; i++){
        powers[i] = (powers[i-1]%mod*prime%mod)%mod;
    }
}

int solve(string pat, string text){
    int n = pat.length();
    int m = text.length();
    int ans = 0;

    // 1st substr
    long long H2 = pat[0]*prime;
    for(int i = 1; i < n; i++){
        H2 = (H2%mod + (pat[i]%mod*powers[i+1])%mod)%mod;
    }

    long long H1 = text[0]*prime;
    for(int i = 1; i < n; i++){
        H1 = (H1%mod + (text[i]%mod * powers[i+1])%mod)%mod;
    }

    if(H1 == H2) ans++;
    
    // remaining substrings
    for(int i=n;i<m;i++){
        H2=(H2%mod*prime%mod)%mod;
        H1=(H1%mod+(text[i]%mod*powers[i+1])%mod-(text[i-n]*powers[i-n+1])%mod+mod)%mod;
        if(H1 == H2) ans++;
    }

    return ans;
}

int main(){
    // TC - O(N+M)
    int t;
    cin>>t;
    precomputePowers();
    while (t--)
    {
        string pat, text;
        cin>>pat>>text;
        if(pat.length() > text.length()){
            cout<<"0\n";
            continue;
        }
        cout<<solve(pat, text)<<"\n";
    }
    
    return 0;
}