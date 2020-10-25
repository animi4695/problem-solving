#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
struct custCompare{
    bool operator()(pair<int, pair<int, int>> & A, pair<int, pair<int, int>> & B){
        return A.first > B.first;
    }
};

void solve(vector<vector<int>> arr){
    vector<int> res;
    // {arr_val, {arr_idx, ele_idx}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, custCompare> pq;

    for(int i = 0; i < arr.size(); i++)
        pq.push({arr[i][0], {i, 0}});
    
    while(pq.top().first != INT_MAX) {
        auto top = pq.top();
        pq.pop();
        cout<<top.first<<" ";
        res.push_back(top.first);
        top.second.second++;
        if(top.second.second >= arr[top.second.first].size()) {
            top.first = INT_MAX;
        }
        else {
            top.first = arr[top.second.first][top.second.second];
        }
        pq.push(top);
    }
}

int main(){
    vector<vector<int>> v = {{1,10,11,15} , {2,4,9,14}, {5,6,8,16}, {3,7,12,13}};
    solve(v);
    return 0;
}