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

int height(Node* root){
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isBalancedBST(Node* root){
    if(root == NULL) return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(abs(leftHeight-rightHeight) <= 1 && isBalancedBST(root->left) && isBalancedBST(root->right)) return true;

    return false;
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

        isBalancedBST(root) == true ? cout<<"Yes\n" : cout<<"No\n";

    }
    
    return 0;
}