#include<iostream>
#include<climits>
#include<vector>

using namespace std;
double findMedianSortedArrays(const vector<int> &A,const vector<int> &B){
    int m = A.size(), n = B.size();

    if(m < n) return findMedianSortedArrays(B, A);

    int l = 0, hi = 2*n;

    while(l <= hi){
        // mid is the possible cut..
        int mid = l + (hi-l)/2;
        int mid1 = m+n - mid;

        double L1 = (mid1 == 0)? INT_MIN : A[(mid1-1)/2];
        double L2 = (mid == 0)? INT_MIN : B[(mid-1)/2];
        double R1 = (mid1 == m*2)? INT_MAX : A[(mid1)/2];
        double R2 = (mid == 2*n)? INT_MAX : B[(mid)/2];

        if(L1 > R2) l = mid+1;
        else if(L2 > R1) hi = mid-1;
        else{
            return (max(L1,L2) + min(R1,R2))/2;
        }
    }

    return -1;
}

int main(){
    // Reference:
    // https://github.com/SrGrace/InterviewBit/blob/master/Binary%20Search/MedianOfArray.cpp

    vector<int> A = {1,2};
    vector<int> B = {3,4};
    cout<<findMedianSortedArrays(A,B);
    return 0;
}