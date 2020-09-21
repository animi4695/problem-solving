#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int BS2(vector<int> &A, int B){
    int lo = 0, hi = A.size()-1;
    int result = -1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(A[mid] == B){
            result = mid;
            lo = mid+1;
        }
        else if(A[mid] < B){
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    return result;
}
int BS1(vector<int> &A, int B){
    // get 1st occurance
    int lo = 0, hi = A.size()-1;
    int result = -1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(A[mid] == B){
            result = mid;
            hi = mid-1;
        }
        else if(A[mid] < B){
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    return result;
}
vector<int> searchRange(vector<int> &A, int B){
    int lo = 0, hi = A.size()-1;
    vector<int> res(2,-1);
    res[0] = BS1(A, B);
    res[1] = BS2(A, B);

    // for(auto r : res) cout<<r<<" ";
    return res;
}

int main(){
    vector<int> A = {5, 7, 7, 8, 8, 10};
    int B = 8;
    searchRange(A, B);
    return 0;
}