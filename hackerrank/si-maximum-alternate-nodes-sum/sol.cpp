#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<unordered_map>

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
pair<int,int> maxSumHelper(Node* node){
    // 1st value in the pair indicates maxSum when a particular node is included
    // 2nd value in the pair indicates maxSum when a particular node is not-included
    if(node == NULL) return {0,0};

    pair<int,int> sum1 = maxSumHelper(node->left);
    pair<int,int> sum2 = maxSumHelper(node->right);
    pair<int,int> sum;

    // this node is included(that means left and right children are not included)
    sum.first = sum1.second + sum2.second + node->val;

    // this node is not included( that means either left or right child is included)
    sum.second = max(sum1.first, sum1.second) + max(sum2.first, sum2.second);

    return sum;

}

int maxSum(Node* root){
    pair<int, int> res = maxSumHelper(root);
    return max(res.first, res.second);
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

        cout<<maxSum(root)<<"\n";
    }
    
    return 0;
}