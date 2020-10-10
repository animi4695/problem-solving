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

vector<int> inorderTraversal(TreeNode* A) {
    // TC - O(N)
    // SC - O(N)

    stack<TreeNode*> st;
    vector<int> res;

    while(A != NULL || !st.empty()) {
        // go to extreme left
        while (A != NULL) {
            st.push(A);
            A = A->left;
        }

        A = st.top();
        st.pop();
        res.push_back(A->val);
        A = A->right;
    }
    return res;
}

vector<int> inorderTraversal2(TreeNode* A){
    // Morris Traversal
    // TC - O(N)
    // SC - O(1)

    vector<int> res;
    TreeNode* curr = A;
    while(curr != NULL){
        if(curr->left == NULL){
            res.push_back(curr->val);
            curr = curr->right;
        }
        else{
            TreeNode* pre = curr->left;
            while(pre->right != NULL && pre->right != curr){
                pre = pre->right;
            }

            if(pre->right == NULL){
                pre->right = curr;
                curr = curr->left;
            }
            else{
                pre->right = NULL;
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return res;
}

int main(){
    return 0;
}