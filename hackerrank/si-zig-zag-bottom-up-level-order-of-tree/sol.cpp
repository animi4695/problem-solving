#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

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

void printLevel(Node* root, int level, bool lefttoright){
    if(root == NULL) return;
    if(level == 1) cout<<root->val<<" ";
    else if(level > 1){
        if(lefttoright){
            printLevel(root->left, level-1, lefttoright);
            printLevel(root->right, level-1, lefttoright);

        }
        else{
            printLevel(root->right, level-1, lefttoright);
            printLevel(root->left, level-1, lefttoright);
        }
    }
}

void zigzagBottomUpLevelOrder(Node* root){
    int h = height(root);
    bool leftoright = false;
    for(int i = h; i >= 1; i--){
        if(i%2 == 0){
            printLevel(root, i, !leftoright);
        }
        else{
            printLevel(root, i, leftoright);
        }
    }
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

        zigzagBottomUpLevelOrder(root);

        cout<<"\n";
    }
    
    return 0;
}