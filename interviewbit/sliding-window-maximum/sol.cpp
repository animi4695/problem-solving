#include<iostream>
#include<climits>
#include<vector>
#include<deque>

using namespace std;
vector<int> slidingMaximum(const vector<int> &A, int B){
    vector<int> result;
    deque<int> dq;
    if(B >= A.size()){
        int max = A[0];
        for(int i = 0 ; i < A.size(); i++){
            if(A[i] > max){
                max = A[i];
            }
        }
        return { max };
    }
    else{
        for(int i = 0; i < A.size(); i++){
            while(!dq.empty() && A[i] >= A[dq.back()]) dq.pop_back();

            dq.push_back(i);

            if( i >= B-1) result.push_back(A[dq.front()]);

            if(dq.front() <= i-B+1){
                dq.pop_front();
            }
        }
    }
    // for(auto c : result) cout<<c<<" ";
    return result;
}
int main(){
    vector<int> A = {1, 3, -1, -3, 5, 3, 6, 7};
    int B = 3;
    slidingMaximum(A, B);
    return 0;
}