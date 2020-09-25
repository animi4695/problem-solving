#include<iostream>
#include<climits>
#include<vector>
#include<stack>

using namespace std;
int largestRectangleArea(vector<int> &A){

    int res = 0;
    A.push_back(0);
    
    stack<int> st;
    
    for(auto i=0; i<A.size(); i++)
    {
        if(st.empty() || A[i] >= A[st.top()])
            st.push(i);
        else
        {
            int j = st.top();
            st.pop();
            res = max(res, A[j]*(st.empty() ? i : i - st.top() - 1));
            i--;
        }
    }
    cout<<res;
    return res;
}
int main(){
    vector<int> A = {90, 58, 69, 70, 82, 100, 13, 57, 47, 18};
    largestRectangleArea(A);
    return 0;
}