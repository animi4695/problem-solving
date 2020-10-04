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

Node* insertNode(Node* root, int k, int depth){
    if(root == NULL){
        cout<<depth<<" ";
        Node* newNode= new Node(k);
        return newNode;
    }
    if(k < root->val)
        root->left = insertNode(root->left, k, depth+1);
    else
        root->right = insertNode(root->right, k, depth+1);
    return root;
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
            root = insertNode(root, arr[i],0);
        }

        cout<<"\n";
    }
    
    return 0;
}