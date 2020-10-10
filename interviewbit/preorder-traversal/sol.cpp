#include<iostream>
#include<climits>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode* A) {
    // DLR
    vector<int> res;
    if(A == NULL) return res;
    stack<TreeNode*> st;
    st.push(A);

    while (!st.empty())
    {
        TreeNode* curr = st.top();
        st.pop();
        res.emplace_back(curr->val);
        if(curr->right != NULL) st.push(curr->right);
        if(curr->left != NULL) st.push(curr->left);

    }

    return res;
}

vector<int> preorderTraversal2(TreeNode* A){
    // Morris Traversal
    // TC - O(N)
    // SC - O(1)

    vector<int> res;
    TreeNode* curr = A;

    while(curr != NULL){
        if(curr->left == NULL){
            res.push_back(curr->val);
            curr  = curr->right;
        }
        else{
            TreeNode* pre = curr->left;
            while(pre->right != NULL && pre->right != curr) pre = pre->right;

            if(pre->right == NULL){
                res.push_back(curr->val);
                pre->right = curr;
                curr = curr->left;
            }
            else{
                pre->right = NULL;
                curr = curr->right;
            }
        }
    }
    return res;
}

int main(){
    return 0;
}