#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
int solve(vector<vector<int>> & A, int n){
    sort(A.begin(), A.end(), [](vector<int> &a, vector<int> &b){ return a[1] < b[1]; });
    // for(auto c : A){
    //     for(auto a : c) cout<<a<<" ";
    //     cout<<"\n";
    // }
    int currEnd = A[0][1];
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(A[i][0] <= currEnd){
            cout<<currEnd<<" "<<A[i][0]<<"\n";
            cnt++;
            currEnd = A[i][1];
        }
    }
    return cnt;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int>(2));
        for(int i = 0; i < n; i++){
            cin>>arr[i][0]>>arr[i][1];
        }
        cout<<"------------------------------";
        cout<<solve(arr, n)<<"\n";
    }
    
    return 0;
}