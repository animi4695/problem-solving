#include<iostream>
#include <climits>
#include<algorithm>
#include<vector>

using namespace std;
int threeSumClosest(vector<int> &A, int B){
    int n = A.size();
    // we sort the array to get the closest easily..
    sort(A.begin(), A.end());

    // the idea is to fix one element and use 2 ptr technique to find the other 2 
    // that are closest to B.

    int ans,minDiff = INT_MAX;
    for(int i = 0 ; i < n-2; i++){
        int p1 = i+1, p2 = n-1;
        while(p1 < p2){
            int temp = A[i] + A[p1] + A[p2];
            int diff = abs(temp-B);
            if(diff == 0){
                return B;
            }
            if(diff < minDiff){
                // found better than prev ans.. so store closest ans and search for next best
                minDiff = diff;
                ans = temp;
            }

            if(temp < B){
                p1++;
            }

            if(temp > B) p2--;
        }
    }
    // cout<<ans;
    return ans;
}

int main(){
    vector<int> A = {-1, 2,1,-4};
    int B = 1;

    threeSumClosest(A, B);
    return 0;
}