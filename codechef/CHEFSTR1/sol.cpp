#include<iostream>
#include <cmath>

using namespace std;
int main(){
    long int t;
    cin>>t;
    while (t--)
    {
        long int n;
        cin>>n;
        long int arr[n];
        for (int i = 0; i < n; i++)
        {
           cin>>arr[i];
        }
        long int ans = 0;
        for(int i = 1; i< n; i++){
            int temp = fabs(arr[i] - arr[i-1]) - 1;
            ans += temp;
            // cout<<arr[i]<<"-"<<arr[i-1]<<"-"<<temp<<"\n";
        }

        cout<<ans<<endl;
    }
    
    return 0;
}