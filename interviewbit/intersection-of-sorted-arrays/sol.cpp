#include<iostream>
#include <limits>
#include<vector>

using namespace std;
vector<int> intersect(const vector<int>& A, const vector<int> &B){
    // 2 ptr approach
    int p1 = 0, p2 = 0;
    int m = A.size();
    int n = B.size();

    vector<int> result;
    while(p1 <m && p2 < n){
        if(A[p1] == B[p2]){
            result.push_back(A[p1]);
            p1++;
            p2++;
        }
        else if(A[p1] < B[p2])
            p1++;
        else
            p2++;
    }

    // for(auto r : result){
    //     cout<<r<<" ";
    // }

    return result;
}


int main(){

    vector<int> A = { 1, 2, 3, 3, 4, 5, 6 };
    vector<int> B = { 3,5}; 

    intersect(A,B);
    return 0;
}