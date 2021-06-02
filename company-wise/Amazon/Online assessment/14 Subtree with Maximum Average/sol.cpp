#include<iostream>
#include<unordered_map>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

struct TreeNode
{
    int val;
    vector<TreeNode*> children;
    TreeNode() : val(0){}
    TreeNode(int x) : val(x) {}
    TreeNode(int x, vector<TreeNode*>  children) : val(x), children(children) {}
};

double ans = INT32_MIN;
TreeNode* res;
vector<double> dfs(TreeNode* node){
    // return value contains {sum_of_children, num_of_children}
    if(node == NULL)
        return {0, 0};
    double currVal = node->val;
    double count = 1;
    for(auto child : node->children){
        vector<double> temp = dfs(child);
        currVal += temp[0];
        count += temp[1];
    }
    double avg = currVal/count;
    if(avg > ans){
        ans = avg;
        res = node;
    }
    return {currVal, count};
}


double maximumAverageSubtree(TreeNode* root) {
    if(root == NULL)
        return 0;
    dfs(root);
    return res->val;
}

int main() {
    // build tree and testcases accordingly
    TreeNode *node0=new TreeNode(1);
    TreeNode *node1=new TreeNode(12);
    TreeNode *node2=new TreeNode(3);
    TreeNode *node3=new TreeNode(7);
    TreeNode *node4=new TreeNode(9);
    TreeNode *node5=new TreeNode(-8);
    node0->children={node1,node2};
    node1->children={node3,node4};
    node2->children={node5};
    int ans=maximumAverageSubtree(node0);
    cout << ans << endl;
    return 0;
}