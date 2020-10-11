#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
int solve(int arr[], int n, int a, int b){
    int res = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            if(sum >= a && sum <= b) res++;
        }
        sum -= arr[i];
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        int arr[n];
        for(int i = 0; i < n; i++) cin>>arr[i];
        int res = solve(arr, n, a, b);
        cout<<res<<"\n";
    }
    
    return 0;
}