#include<iostream>
#include <limits>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
    int t;

    cin>> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }

        sort(arr.begin(), arr.end());
        
        bool ans = true;
        for(int i = 0; i < n-1; i++){
            if(arr[i+1]-arr[i] > 1){
                ans = false;
                break;
            }
        }

        if(ans == true){
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    
    return 0;
}