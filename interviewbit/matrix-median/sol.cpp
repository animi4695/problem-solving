#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
int findMedian(vector<vector<int>> &A){
    int r = A.size();
    int c = A[0].size();
    int desired = (r*c+1)/2;
    int minm = INT_MAX, maxm = INT_MIN;
    // find min and max of the matrix
    for(int i = 0; i < r; i++){
        minm = min(minm, A[i][0]);
        maxm = max(maxm, A[i][c-1]);
    }

    while(minm < maxm){
        int mid = (minm + maxm)/2;

        int count = 0;
        for(int i = 0 ; i < r; i++){
            // search the smallest value which is greater than mid. This gives us the number of elements 
            // smaller than mid.
            count += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        }
        if(count < desired){
            minm = mid+1;
        }
        else{
            maxm = mid;
        }
    }
    return minm;
}
int main(){
    vector<vector<int>> A = { {1, 3, 5}, {2, 6, 9}, {3, 6, 9} };
    cout<<findMedian(A);
    return 0;
}