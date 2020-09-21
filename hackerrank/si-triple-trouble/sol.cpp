#include<iostream>
#include <limits>

using namespace std;
bool checkbit(int N, int i){
    // cout<<N<<"-";
    return (N>>i)&1;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin>>arr[i];
        int ans = 0;
        for (int i = 0; i < 31; i++)
        {
            int setCount = 0;
            for (int j = 0; j < n; j++)
            {
                if(checkbit(arr[j], i)){
                     setCount++;
                }
            }
            // cout<<setCount<<"\n";

            if(setCount%3 != 0){
                ans += 1<<i;
            }
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}