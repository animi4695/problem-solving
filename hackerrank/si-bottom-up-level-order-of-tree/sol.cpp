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

void bottomupLevelOrder(Node* root){
    // TC - O(N)
    // SC - O(1)
    // IDEA - Maintain queue and stack. queue for processing the nodes one by one, 
    // and stack is to maintain them in reverse order
    if(root == NULL) return;

    // stack stores the value and level of the node.
    stack<pair<int,int>> st;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    int lev = 0;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        lev = max(lev, curr.second + 1);
        st.push({curr.first->val, curr.second + 1 });

        // first push right and then left. the order is important for bottom-up level order.
        if(curr.first->right){
            q.push({curr.first->right, curr.second + 1});
        }

        if(curr.first->left){
            q.push({curr.first->left, curr.second + 1});
        }
    }

    while(!st.empty()){
        auto t = st.top();
        if(lev == t.second){
            cout<<t.first<<" ";
            st.pop();
        }
        else{
            lev--;
            cout<<"\n";
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

        bottomupLevelOrder(root);

        cout<<"\n\n";
    }
    
    return 0;
}