#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;

void solve(int arr[], int n){
    // dp[i] = max subarray sum till i including i.
   int max_ending_here = 0;
   int finalAns = 0;
   int start = 0;
   int end = 0;
   int _start = 0;

   for(int i = 0; i < n; i++){
       max_ending_here = max_ending_here + arr[i];
       if(max_ending_here < 0){
           _start = i+1;
           max_ending_here = 0;
       }
       
       if(max_ending_here > finalAns){
           finalAns = max_ending_here;
           start = _start;
           end = i;
       }
   }
   cout<<finalAns<<" "<<start<<" "<<end<<"\n";
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++) cin>>arr[i];

        solve(arr, n);
    }
    
    return 0;
}