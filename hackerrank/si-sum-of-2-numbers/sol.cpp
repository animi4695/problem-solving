#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
bool solve(int arr[], int n, int sum){
    // 2-ptr technique
    int p1 = 0, p2 = n-1;
    while(p1 < p2){
        int val = 2*(arr[p1] + arr[p2]);
        if(val == sum){
            return true;
        }
        else if(val < sum){ p1++; }
        else{
            p2--;
        }
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            sum += arr[i];
        }
        sort(arr, arr+n);

        if(solve(arr, n, sum)){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    
    return 0;
}