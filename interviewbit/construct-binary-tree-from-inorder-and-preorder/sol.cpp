#include<iostream>
#include<climits>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int search(vector<int> inorder, int lo , int hi, int val){
    for(int i = lo; i <= hi; i++){
        if(inorder[i] == val){
            return i;
        }
    }

    return -1;
}

TreeNode* makeTree(vector<int> &preorder, vector<int> &inorder, int & pos, int low, int high){
    if(low > high) return NULL;
    TreeNode* root = new TreeNode(preorder[pos++]);
    if(low == high) return root;
    int idx = search(inorder, low, high, root->val);
    root->left = makeTree(preorder, inorder, pos, low, idx-1);
    root->right = makeTree(preorder, inorder, pos, idx+1, high);

    return root;
}

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
    if(inorder.empty() || preorder.empty()) return NULL;
    int pos = 0;
    return makeTree(preorder, inorder, pos, 0, inorder.size()-1);
}

int main(){
    return 0;
}