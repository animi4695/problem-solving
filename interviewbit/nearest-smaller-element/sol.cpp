#include<iostream>
#include<climits>
#include<vector>
#include<stack>

using namespace std;
vector<int> prevSmaller(vector<int> &A){
    stack<int> st;
    int n = A.size();
    vector<int> ans(n, -1);

    for(int i = 0; i < n; i++){
        while (!st.empty() && st.top() >= A[i]) st.pop();

        if(!st.empty()) ans[i] = st.top();
        st.push(A[i]);
    }
    return ans;
}

int main(){
    vector<int> A = {4, 5, 2, 10, 8};
    prevSmaller(A);

    return 0;
}