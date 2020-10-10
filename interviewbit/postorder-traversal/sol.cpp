#include<iostream>
#include<climits>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> postorderTraversal(TreeNode* A) {
    // LRD
    vector<int> res;
    if(A == NULL) return res;
    stack<TreeNode*> st;
    st.push(A);

    while(!st.empty()){
        TreeNode* curr = st.top();
        res.emplace_back(curr->val);
        st.pop();

        if(curr->left != NULL) st.push(curr->left);
        if(curr->right != NULL) st.push(curr->right);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    return 0;
}