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

void zigzagLevelOrder(Node* root){
    // TC - O(N)
    // SC - N + N = O(N)
    // IDEA - maintain two stacks, one for the currentLevel and the other nextLevel. Also maintain boolean(leftoright)
    // to print in the zig zag order.
    if(root == NULL) return;

    stack<Node*> currLevel, nextLevel;
    currLevel.push(root);
    bool lefttoright = true;

    while (!currLevel.empty())
    {
        Node* temp = currLevel.top();
        currLevel.pop();

        if(temp != NULL){
            cout<<temp->val;

            if(lefttoright){
                if(temp->right) nextLevel.push(temp->right);
                if(temp->left) nextLevel.push(temp->left);
            }
            else{
                if(temp->left) nextLevel.push(temp->left);
                if(temp->right) nextLevel.push(temp->right);
            }
        }

        if(currLevel.empty()){
            lefttoright = !lefttoright;
            swap(currLevel, nextLevel);
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

        zigzagLevelOrder(root);

        cout<<"\n";
    }
    
    return 0;
}