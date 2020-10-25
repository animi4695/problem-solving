#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;
void maxPairSum(vector<int>& A, vector<int>& B, int n, int k){
    vector<int> res;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    priority_queue<pair<int, pair<int,int>>> pq;
    set<pair<int, int> > uset;
    pq.push({A[n-1]+B[n-1], {n-1, n-1}});
    uset.insert({n-1,n-1});

    for(int count = 0; count < k; count++){
        auto temp = pq.top();
        pq.pop();
        res.push_back(temp.first);

        int i = temp.second.first;
        int j = temp.second.second;
        int sum = A[i-1]+B[j];
        
        if(i > 0 && uset.find({i-1, j}) == uset.end()){
            pq.push({sum, {i-1,j}});
            uset.insert({i-1, j});
        }

        sum = A[i]+B[j-1];

        if(j > 0 && uset.find({i, j-1}) == uset.end()){
            pq.push({sum, {i, j-1}});
            uset.insert({i,j-1});
        }
    }

    for(int i = 0; i < k; i++){
        cout<<res[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        vector<int> A(n), B(n);
        for(int i = 0; i < n; i++) cin>>A[i];
        for(int i = 0; i < n; i++) cin>>B[i];
        maxPairSum(A,B,n,k);
    }
    
    return 0;
}