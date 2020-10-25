#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
struct Trie {
    Trie* c[26];
    int count;
    Trie(){
        for(int i = 0 ; i < 26; i++){
            c[i] = NULL;
            count = 0;
        }
    }
};

void insert(Trie* root, string s){
    reverse(s.begin(),s.end());
    // int val = root->count;
    for(int i = 0; i < s.length(); i++){
        int idx = s[i]-'a';
        if(root->c[idx] == NULL){
            root->c[idx] = new Trie();
            // root->c[idx]->count = max(root->count, (int)s.length());
        }
        root = root->c[idx];
        root->count = max(root->count, (int)s.length());
    }
}

int query(Trie* root, string s){
    reverse(s.begin(), s.end());

    for(int i = 0; i < s.length(); i++){
        int idx = s[i]-'a';
        if(root->c[idx] == NULL) break;
        root = root->c[idx];
    }
    return root->count;
}

int main(){
    int n;
    cin>>n;
    Trie* root = new Trie();
    for(int i = 0 ; i < n; i++){
        string s;
        cin>>s;
        insert(root, s);
    }
    int q;
    cin>>q;
    for(int i = 0; i < q; i++){
        string val;
        cin>>val;
        cout<<query(root, val)<<"\n";
    }
    
    return 0;
}