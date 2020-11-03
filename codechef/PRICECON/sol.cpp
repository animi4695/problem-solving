#include<iostream>

using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[n];
        int potentialProfit = 0;
        int potentialLoss = 0;
        for(int i = 0; i< n; i++){
            cin >> arr[i];
            potentialProfit += arr[i];
            if(arr[i] > k){
                potentialLoss += k;
            }
            else{
                potentialLoss += arr[i];
            }
        }
        int ans = potentialProfit-potentialLoss;
        cout<<ans<<endl;
    }
    
    return 0;
}