#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
struct Trie {
    Trie* c[2];
    Trie(){
        for(int i = 0; i < 2; i++) c[i] = NULL;
    }
};

bool checkbit(int N, int i){
    return (N>>i)&1;
}

void insert(Trie* root, int x, int bits){
    for(int b = bits; b >= 0; b--){
        int idx = checkbit(x, b) ? 1 : 0;
        if(root->c[idx] == NULL)
           root->c[idx] = new Trie();
        root = root->c[idx];
    }
}

int query(Trie* root, int x, int bits){
    int ans = 0;
    for(int b = bits; b >=0; b--){
        int idx = checkbit(x, b) ? 1 : 0;
        if(root->c[1-idx] != NULL){
            root = root->c[1-idx];
            ans = ans + (1<<b);
        }
        else{
            root = root->c[idx];
        }
    }
    return ans;
}

int main(){
    // Trie
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int maxArr = INT_MIN;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            maxArr = max(maxArr, arr[i]);
        }

        int bits = log2(maxArr);
        Trie* root = new Trie();
        for(int i = 0; i < n; i++)
            insert(root, arr[i], bits);
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, query(root, arr[i], bits));
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}