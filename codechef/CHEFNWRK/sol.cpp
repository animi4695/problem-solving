#include<iostream>
#include<vector>

using namespace std;
int solve(vector<int>& arr, int n, int k){
    int wsum = 0;
    int tripCount = 0;
    for(int i = 0 ; i < n; i++){
        if(arr[i] > k){
            return -1;
        }
        else{
            while (wsum <= k && i < n)
            {
                // cout<<i;
                wsum += arr[i];
                i++;
            }
            if(wsum > k){
                i = i-2;
            }
            tripCount++;
            wsum = 0;  
        }
    }
    return tripCount;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n,0);
        for(int i = 0; i < n; i++) cin>>arr[i];

        cout<<solve(arr, n, k)<<"\n";
    }
    
    return 0;
}