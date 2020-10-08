#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<queue>

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

bool isCompleteBT(Node* root){
    if(root == NULL) return true;

    queue<Node*> q;
    q.push(root);

    bool flag = false; // set to true when a non-full node is found.
    // full node :  node which has both left and right children
    // once the flag is set to true. from there on, only leaf nodes should be there.
    while(!q.empty()){
       Node* temp = q.front();
       q.pop();

       if(temp->left){
           if(flag == true) return false;
           q.push(temp->left);
       }
       else flag = true;

       if(temp->right){
           if(flag == true) return false;
           q.push(temp->right);
       }
       else flag = true;
    }
    return true;
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

        isCompleteBT(root) ? cout<<"Yes\n" : cout<<"No\n";

    }
    
    return 0;
}