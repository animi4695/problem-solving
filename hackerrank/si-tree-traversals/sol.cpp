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

void preOrder(Node* root){
    // DLR
    if(root == NULL) return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    // LRD
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

void inOrder(Node* root){
    // LDR
    if(root == NULL) return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
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

        preOrder(root);
        cout<<"\n";
        inOrder(root);
        cout<<"\n";
        postOrder(root);
        cout<<"\n";
        cout<<"\n";
    }
    
    return 0;
}