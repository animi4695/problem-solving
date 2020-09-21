#include<iostream>
#include <limits>

using namespace std;
void insertionsort(int arr[], int n){
    int i, key, j;
    for(i = 1 ; i < n; i++){
        key = arr[i];
        j = i-1;

        while (j >=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        cout<<j+1<<" ";
        arr[j+1] = key;
    }

    // for(int i = 0; i < n; i++){
    //     cout<<arr[i];
    // }
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0 ; i < n; i++) cin>>arr[i];

        insertionsort(arr, n);
        cout<<"\n";
    }
    
    return 0;
}