#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
struct Node {
    bool isElement;
    Node* c[10];
    Node(){
        for(int i = 0 ; i < 10; i++) c[i] = NULL;
        isElement = false;
    }
};

bool noPrefixSet(Node* curr, string s){
    Node* root = curr;
    for(int i = 0; i < s.length(); i++){
        int idx = s[i]-'a';
        if(root->c[idx] == NULL){
            root->c[idx] = new Node();
        }
        root = root->c[idx];
        if(root->isElement){
            return true;
        }
    }
    root->isElement = true;

    for(int i = 0; i < 10; i++) {
        if(root->c[i] != NULL) return true;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    Node* root = new Node();
    bool flag;
    while (t--)
    {
        string s;
        cin>>s;
        flag = noPrefixSet(root, s);
        if(flag){
            cout<<"BAD SET\n"<<s<<"\n";
            break;
        }
    }
    if(flag == false) cout<<"GOOD SET\n";
    return 0;
}