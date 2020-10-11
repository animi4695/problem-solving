#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>

using namespace std;
int solve(string a, string b){
    int ans = 0;
    int countA[26] = {0};
    int countB[26] = {0};

    for(int i = 0; i < a.length(); i++) countA[a[i]-'a']++;
    for(int i = 0; i < b.length(); i++) countB[b[i]-'a']++;

    for(int i = 0; i < 26; i++){
        int val = countA[i] - countB[i];
        ans += val > 0 ? val : -val;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a, b;
        cin>>a>>b;
        cout<<solve(a,b)<<"\n";
    }
    
    return 0;
}