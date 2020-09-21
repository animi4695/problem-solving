#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
int powerOfTwo(int n)
{
    // if n pwr of 2 return 1 or else return 0
    return n && (!(n & (n - 1)));
}

bool checkbit(int n, int i){
    return (n>>i)&1;
}

void allsubsets(int arr[], int n, int subsets[], int idx){
    if(n == idx) { 
        
    }

    allsubsets(arr, n , subsets, idx +1);
    allsubsets(arr, n , subsets, idx);
}

void solve(int arr[], int n){
    bool isFound = false;
    for(int i = 0; i < 1<<n; i++){
        int result = 0;
        vector<int> subset(n);
        for(int j = 0; j < 31; j++){
            if(checkbit(i,j)){
                 subset[j] = arr[j];
                 result &= subset[j];
            }
        }
        for(auto s : subset){
            cout<<s<<" ";
        }
        cout<<"\n";
        // cout<<result;
        if(powerOfTwo(result) == 1){
            cout<<"YES\n";
            isFound = true;
            break;
        }
    }
    if(isFound == false) cout<<"No\n";
    
}
int main(){
    // pending TODO
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i <n; i++) cin>>arr[i];
        solve(arr,n);
    }
    
    return 0;
}