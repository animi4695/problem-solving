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

bool isBST(Node* root, int a, int b){
    // LDR
    if(root==NULL) {
        return true;
    }
    if( (a<root->val && b>root->val) && isBST(root->left, a, root->val) && isBST(root->right, root->val, b)) {
        return true;
    }
    return false;
}

Node* constructCBT(int arr[], Node* root, int i, int n){
    if(i < n){
        Node* temp = new Node(arr[i]);
        root = temp;

        root->left = constructCBT(arr, root->left, 2*i+1, n);
        root->right = constructCBT(arr, root->right, 2*i+2, n);
    }
    return root;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++) cin>>arr[i];
        Node* root = NULL;
        root = constructCBT(arr, root, 0, n);
        isBST(root, -1, 10001) ? cout<<"True\n" : cout<<"False\n";
    }
    
    return 0;
}