#include<iostream>
#include<cmath>

using namespace std;
int solve(int arr[], int n, int k){
    int queries = 0, res = 0;
    for(int i = 0; i < n; i++){
        queries += arr[i];
        if(queries < k) return i+1;
        queries -= k;
    }
    if(queries > 0){
        res = n + ceil(queries/k);
    }

    return res;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i = 0; i < n; i++) cin>>arr[i];

        cout<<solve(arr, n, k)<<"\n";
    }
    
    return 0;
}