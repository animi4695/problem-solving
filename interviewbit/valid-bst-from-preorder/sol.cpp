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

int search(vector<int> & inorder, int low, int high, int val){
    for(int i = low; i <= high; i++){
        if(inorder[i] == val)
           return i;
    }
    return -1;
}

TreeNode* makeTree(vector<int> & preorder, vector<int> & inorder, int pos, int low, int high){
    if(low > high) return NULL;
    int idx = search(inorder, low, high, preorder[pos]);
    TreeNode* root = new TreeNode(preorder[pos++]);
    if(low == high) return root;
    root->left = makeTree(preorder, inorder, pos, low, idx-1);
    root->right = makeTree(preorder, inorder, pos, idx+1, high);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    if(preorder.empty() || inorder.empty()) return NULL;
    int pos = 0;
    return makeTree(preorder, inorder, pos, 0, inorder.size());
}


// this is the answer
int solve(vector<int> & A){
    int a=0,b=1,c=2;

    if(A.size() <= 2)
    return 1;

    while(c < A.size())
    {
        if(A[a] < A[b] && A[b] > A[c] && A[c] < A[a])
            return 0;
        a++; b++; c++;
    }
    return 1;
}

int solve2(vector<int> & A){
    stack<int> st;
    int root = INT_MIN;

    for(int i = 0 ; i < A.size(); i++){
        if(A[i] < root) return false;

        while(!st.empty() && st.top() < A[i]){
            root = st.top();
            st.pop();
        }

        st.push(A[i]);
    }

    return true;
}

int main(){
    return 0;
}