#include<iostream>
#include<algorithm>

using namespace std;
bool checkAnd(int arr[], int n){
    for(int i = 0 ; i < n-1; i++){
        if((arr[i]&arr[i+1]) <= 0) return false;
    }
    return true;
}
void solve(int n){
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = i+1;
    }

    bool flag = false;
    do { 
		if(checkAnd(arr,n) == true){
            flag = true;
            break;
        }
	} while (next_permutation(arr, arr + n));

    if(flag){
        for(auto a : arr) cout<<a<<" ";
            cout<<"\n";
    }
    else
        cout<<"-1\n";
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        solve(n);
    }
    
    return 0;
}