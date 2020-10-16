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

bool findPath(Node* root, int s, vector<Node*> &L){
    if(root == NULL) return false;

    if(root->val == s){
        L.push_back(root);
        return true;
    }

    if(findPath(root->left, s, L)){
        L.push_back(root);
        return true;
    }

    if(findPath(root->right, s, L)){
        L.push_back(root);
        return true;
    }
    return false;
}

int cnt(Node* S, int k){
    if(S == NULL || k < 0) return 0;
    if(k == 0) return 1;
    return cnt(S->left, k-1) + cnt(S->right, k-1);
}
int ans = 0;

int printkdistanceNode(Node* root, Node* target, int k){
    if(root == NULL) return -1;

    if(root == target) {
        ans += cnt(root, k);
        return 0;
    }

    int dl = printkdistanceNode(root->left, target, k);
    if(dl != -1){
        if(dl+1 == k){
            ans++;
        }
        else{
            ans += cnt(root->right, k-dl-2);
        }
        return 1+dl;
    }

    int dr = printkdistanceNode(root->right, target, k); 
    if (dr != -1) 
    { 
         if (dr + 1 == k) 
            ans++;
         else
            ans += cnt(root->left, k-dr-2); 
         return 1 + dr; 
    } 
  
    // If target was neither present in left nor in right subtree 
    return -1; 
}

int solve(Node* root, int s, int k){
    vector<Node*> L;
    findPath(root, s, L);
    // L[0] has our s Node.
    printkdistanceNode(root, L[0], k);
    return ans;
}

int main(){

    // fast-io
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t;
    cin>>t;
    while (t--)
    {
        int n,s,k;
        cin>>n>>s>>k;
        int arr[n];
        for(int i = 0; i < n; i++) cin>>arr[i];
        Node* root = NULL;
        for(int i = 0; i < n; i++){
            root = insertNode(root, arr[i]);
        }
        cout<<solve(root, s, k)<<'\n';
    }
    
    return 0;
}