#include<iostream>
#include <limits>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        n++;
        int sum = (n*(n+1))/2;
        int sum2 = 0;
        
        for(int i = 0; i<n-1;i++){
            sum2 += arr[i];
        }

        cout<<sum-sum2<<"\n";;
    }
    
    return 0;
}