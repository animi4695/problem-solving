#include<iostream>
#include <limits>

using namespace std;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionsort(int arr[], int n){
    // There are 4 ways to do selection sort
    // 1) Find max and swap it to the end
    // 2) Find max and swap it to the beginning
    // 3) Find min and swap it to the end
    // 4) Find min and swap it to the beginning
    // As per the question.. we are taking the 1st step and printing the index.
    for (int i = 0, j = n-1; j > 0; i++, j--)
    {
        int maxidx = 0;
        for(int k = 0; k <= j; k++){
            if(arr[k] > arr[maxidx])  maxidx = k;
        }
        cout<<maxidx<<" ";
        swap(&arr[maxidx], &arr[j]);
    }
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

        selectionsort(arr, n);

        cout<<"\n";
    }
    
    return 0;
}