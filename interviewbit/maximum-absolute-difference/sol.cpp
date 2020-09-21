#include<iostream>
#include <limits>
#include<vector>

using namespace std;
int maxArr(vector<int>& A);

int main(){
    vector<int> A = {1, 3,-1};
    
    cout<<maxArr(A);
    return 0;
}

int maxArr(vector<int>& A){

    // Brute Force
    // int N = A.size();
    // int ans = INT32_MIN;
    // for(int i = 0 ; i < N; i++){
    //     for(int j = i; j < N; j++){
    //         int tempX = (A[i]-A[j]) < 0? -(A[i]-A[j]) : A[i]-A[j];
    //         int tempY = (i - j) < 0 ? -(i-j) : i-j;
    //         int x = tempX + tempY;
    //         ans = max(ans, x);
    //     }
    // }
    
    // optimized

    int ans = 0, n = A.size(); 
    
    int max1 = INT32_MIN, max2 = INT32_MIN;
    int min1 = INT32_MAX, min2 = INT32_MAX;
    
    for(int i = 0; i < n; i++){
        max1 = max(max1, A[i] + i);
        max2 = max(max2, A[i] - i);
        min1 = min(min1, A[i] + i);
        min2 = min(min2, A[i] - i);
    }   
    ans = max(ans, max2 - min2);
    ans = max(ans, max1 - min1);

    
    return ans;
}