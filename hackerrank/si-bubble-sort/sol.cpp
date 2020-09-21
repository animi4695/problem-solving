#include<iostream>
#include <limits>

using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int bubblesort(int arr[], int n){
    // compare two elements at a time
    int count = 0;
    for(int i = 0 ; i < n-1; i++){
        for(int j = 0 ; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                count++;
            }
        }
    }
    return count;
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

        int count = bubblesort(arr, n);
        cout<<count<<"\n";
    }
    
    return 0;
}