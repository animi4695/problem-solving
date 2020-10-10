#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#include<map>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traversal(TreeNode* root, int slope,
            vector<vector<int>>& lines) {
    if(!root)
        return;
    // if this is the first pt on the lin`e
    if(lines.size() <= slope)
        lines.emplace_back(vector<int>{});  
    // add the current node to its appropriate line
    lines[slope].emplace_back(root->val);

    traversal(root->left, slope+1, lines);
    traversal(root->right, slope, lines);
}

vector<int> solve(TreeNode* A) {
    vector<vector<int>> lines;
    traversal(A, 0, lines);
    vector<int> res;
    for(auto line : lines){
        res.insert(res.end(), line.begin(), line.end());
    }

    return res;
}

vector<int> solve2(TreeNode* A){
    // iterative version
    // preorder to maintain the order of the output
    vector<int> res;
    if(A == NULL) return res;
    queue<TreeNode*> q;
    q.push(A);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        while(temp){
            res.push_back(temp->val);
            if(temp->left != NULL)  q.push(temp->left);
            temp = temp->right;
        }
    }

    return res;
}

int main(){
    return 0;
}