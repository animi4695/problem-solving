#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin>>arr[i];
        
        bool minStep = false;
        sort(arr.begin(), arr.end());
        int i = n-1;
        for (i = n-1; i >=0; i--)
        {
            if(k%arr[i] == 0){
                minStep = true;
                break;
            }
        }

        if(minStep) cout<<arr[i]<<"\n";
        else
        {
             cout<<"-1\n";
        }
    }
    
    return 0;
}