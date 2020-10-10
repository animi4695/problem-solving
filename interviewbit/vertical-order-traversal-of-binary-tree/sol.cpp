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

vector<vector<int>> verticalOrderTraversal(TreeNode* A){
    vector<vector<int>> res;

    if(A == NULL) return res;

    // queue contains TreeNode and level
    queue<pair<TreeNode*, int>> q;
    map<int, vector<int>> mp;
    q.push({A, 0});

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        if(temp.first->left){
            q.push({temp.first->left, temp.second-1});
        }

        if(temp.first->right){
            q.push({temp.first->right, temp.second+1});
        }

        mp[temp.second].push_back(temp.first->val);
    }

    for(auto it : mp){
        res.push_back(it.second);
    }
    return res;
}

int main(){
    return 0;
}