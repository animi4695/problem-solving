#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;

int kadane(int arr[], int n){
    int maxSum = 0, currSum = 0;
    for(int i = 0; i < n; i++){
        currSum = arr[i] + max(currSum, 0);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}


int solve(int arr[], int n){
    // In case of circular array, we have 2 cases.
    //  1) max Subarray without considering circular.
    //  2) maxSubarray wrapped. 
    // i.e ans = max(maxsubarray Sum, total sum - minsubarrysum)
    
    //edge case
    int min = INT_MIN;
    bool pos = false;
    for(int i = 0; i < n; i++){
        if(arr[i] >= 0){
            pos = true;
            break;
        } else {
            if(arr[i] > min)
                min = arr[i];
        }
    }

    if(!pos) return min;

    //find minSubArraySum
    for(int i = 0; i < n; i++)
        arr[i] = -arr[i];
    
    // run kandane's algorithm
    int minSubArraySum = kadane(arr, n);

    // restore the array
    int totalSum = 0;
    for(int i = 0; i < n; i++){
        arr[i] = -arr[i];
        totalSum += arr[i];
    }
    int maxSubArraySum = kadane(arr, n);
    int ans = max(maxSubArraySum, totalSum + minSubArraySum);
    return ans;
}

int main(){

    // https://medium.com/@saurav.agg19/maximum-sum-circular-subarray-437e6decd538
    
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];

        for(int i = 0; i < n; i++) cin>>arr[i];

        cout<<solve(arr, n)<<"\n";
    }
    
    return 0;
}