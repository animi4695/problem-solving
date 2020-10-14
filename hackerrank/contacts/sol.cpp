#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
struct Node {
    int count;
    Node* c[26];
    Node(){
        for(int i = 0; i < 26; i++) c[i] = NULL;
        count = 0;
    }
};

void insert(Node* root, string w){
    for(int i = 0; i < w.length(); i++){
        int idx = w[i]-'a';
        if(root->c[idx] == NULL){
            root->c[idx] = new Node();
        }
        root = root->c[idx];
        root->count++;
    }
}

int find(Node* root, string w){
    for (int i = 0; i < w.length(); i++) {
        int idx = w[i]-'a';
        if(root->c[idx] == NULL) return 0;
        root = root->c[idx];
    }
    return root->count;
}

int main(){
    // Trie
    Node* root = new Node();
    int t;
    cin>>t;
    while (t--)
    {
        string s, w;
        cin>>s>>w;
        if(s == "add"){
            insert(root, w);
        }
        else{
            cout<<find(root, w)<<"\n";
        }
    }
    
    return 0;
}