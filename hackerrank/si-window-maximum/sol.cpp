#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<deque>

using namespace std;
int findMax(int arr[], int n, int a, int b){
    int max = arr[a];
    for(int i = a+1; i <= b; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

int solve1(int arr[], int n, int k){
    // idea -> push indexes of potential maximum and pop indexes which will never be max in any window.
    deque<int> dq;
    int result = 0;
    for(int i = 0; i < n; i++){
        // pop elements which will never be max in any window
        while(!dq.empty() && arr[i] >= arr[dq.back()]) dq.pop_back();
        dq.push_back(i);

        if(i >= k-1){
            result += arr[dq.front()];
        }

        // out of bounds index check
        if(dq.front() <= i-k+1) dq.pop_front();
    }
    return result;
}

int solve(int arr[], int n, int k){
    int result = 0;
    if(n < k) return result;
    int i = 0, j = k-1;
    while(j < n){
        int r = findMax(arr, n, i, j);
        result += r;
        j++;
        i++;
    }

    return result;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i = 0; i < n; i++) cin>>arr[i];
        cout<<solve1(arr, n, k)<<"\n";
    }
    
    return 0;
}