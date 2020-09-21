#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
bool isValid(vector<int> &arr,int n, int threshold, int k);
int sum(vector<int>& arr, int idx, int n);
void solve(vector<int>& arr, int n, int k, int currAns, int idx);
void solve1(vector<int> arr, int n, int k, int sum_of_arr, int max_of_arr);


int ans = INT_MAX;
int sum(vector<int>& arr, int idx, int n){
    int s = 0; // sum from idx to n;
    for(int i = idx; i < n; i++){
        s += arr[i];
    }

    return s;
}
void solve(vector<int>& arr, int n, int k, int currAns, int idx){
    // bruteforce solution
    // TC - (N-1)C(K-1)
    // Summary: 
    //       The idea is to consider all the possible divisions and get the min possible answer out of it
    // params : arr - tasks, n - num of tasks, currAns - current possible ans, idx - index we made divisions at

    // base condition
    if(k == 1 || idx == n){
        // last worker
        // consider giving all the remaining tasks to last worker...
        currAns = max(currAns, sum(arr, idx, n));
        ans = min(currAns, ans);
        return;
    }

    int s = 0;
    for(int i = idx; i < n; i++){
        s = s+arr[i];
        currAns = max(currAns, s);
        solve(arr, n, k-1, currAns, i+1);
    }
}

void solve1(vector<int> arr, int n, int k, int sum_of_arr, int max_of_arr){
    // optimized solution
    // TC - O(N*Log(sum))
    // SC - O(1)
    // Idea - 
    //      Let's assume something as an answer, check if that can be a possible ans. If so, store it
    // and search for next best answer..
    // -> if something is not an ans... then everything less than that will also not be an ans.
    // -> if something is an ans... then everything greater than that will also be an ans.
    
    // Apply Binary Search 
    int lo = max_of_arr, hi = sum_of_arr;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        // check if mid can be the correct cut for all the tasks.
        if(isValid(arr,n,mid, k) == true){
            ans = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
}

bool isValid(vector<int> &arr,int n, int threshold, int k){
    int timetaken = 0;
    int workers = 1;
    for(int i = 0; i < n ; i++){
        timetaken += arr[i];
        if(timetaken > threshold){
            timetaken = arr[i];
            workers++;
            if(workers > k) return false;
        }
    }

    return workers<=k;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        ans = INT_MAX;
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        int max_of_arr = INT_MIN;
        int sum_of_arr = 0;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            sum_of_arr += arr[i];
            max_of_arr = max(max_of_arr, arr[i]);
        }

        // bruteforce 
        // solve(arr, n, k, 0 , 0);

        // optimized
        solve1(arr, n, k, sum_of_arr, max_of_arr);

        cout<<ans<<"\n";
    }
    
    return 0;
}