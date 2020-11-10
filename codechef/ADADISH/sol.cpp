#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;
int solve(int arr[], int n){
    int burner[2] = {0};
    if(n == 1) return arr[0];
    for(int i = n-1; i >= 0; i--){
        int idx = burner[0] < burner[1] ? 0 : 1;
        if(idx == 0){
            burner[0] += arr[i];
        }
        else{
            burner[1] += arr[i];
        }
    }
    return max(burner[0], burner[1]);
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
        // sort them in descending order
        sort(arr, arr+n);
        cout<<solve(arr, n)<<"\n";
    }
    
    return 0;
}