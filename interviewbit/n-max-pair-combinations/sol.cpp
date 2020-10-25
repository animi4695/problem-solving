#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B){
    int n = B.size();
    priority_queue<pair<int, pair<int, int>>> pq;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    set<pair<int, int>> st;

    pq.push({A[n-1]+B[n-1], {n-1, n-1}});
    st.insert({n-1, n-1});

    vector<int> res;

    while(n--){
        auto top = pq.top();
        pq.pop();
        res.push_back(top.first);
        int L = top.second.first;
        int R = top.second.second;

        if(R > 0 && L >=0 && st.find({L, R-1}) == st.end()){
            pq.push({A[L]+B[R-1], {L, R-1}});
            st.insert({L, R-1});
        }

        if(L > 0 && R >= 0 && st.find({L-1, R}) == st.end()){
            pq.push({A[L-1]+B[R], {L-1, R}});
            st.insert({L-1, R});
        }
    }

    return res;
}
int main(){
    return 0;
}