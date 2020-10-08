#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<map>

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

void verticalOrder(Node* root, map<int, vector<int>>& mp, int v, int minV){
    if(root == NULL) return;
    
    mp[v].push_back(root->val);
    minV = min(v, minV);

    verticalOrder(root->left, mp, v-1, minV);
    verticalOrder(root->right, mp, v+1, minV);

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

        map<int, vector<int>> mp;
        verticalOrder(root, mp, 0, 0);
        for(auto m : mp){
            sort(m.second.begin(), m.second.end());
            for(auto vec : m.second){
                cout<<vec<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    
    return 0;
}