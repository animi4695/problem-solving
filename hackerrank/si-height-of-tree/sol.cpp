#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

Node* insertNode(Node* root, int k){
    if(root == NULL){
        Node* newNode= new Node(k);
        return newNode;
    }
    if(k < root->val)
        root->left = insertNode(root->left, k);
    else
        root->right = insertNode(root->right, k);
    return root;
}

int findHeight(Node* root){
    if(root == NULL) return -1;
    return 1 + max(findHeight(root->left), findHeight(root->right));
}

int main(){

    // fast-io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++) cin>>arr[i];
        Node* root = NULL;
        for(int i = 0; i < n; i++){
            root = insertNode(root, arr[i]);
        }

        int height = findHeight(root);
        cout<<height<<"\n";
    }
    
    return 0;
}