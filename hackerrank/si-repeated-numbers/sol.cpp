#include<iostream>
#include <limits>

using namespace std;
bool checkbit(int n, int i){
    return (n>>i)&1;
}

void repeatedNumbers(int arr[], int arrSize){
    // unique arr size
    int n = arrSize-2;
    // xor of arr[1...N] and inputarr
    // contains XOR of two repeated elements
    int XOR = arr[0];
    for (int i = 1; i < arrSize; i++) XOR ^= arr[i];
    for (int i = 1; i <= n; i++) XOR ^= i;
    
    // first set bit in XOR
    int setBitNo = 0;
    while (XOR != 0) {
        if ((XOR & 1) != 0) {
            break;
        }
        setBitNo++;
        XOR >>= 1;
    }

    int x = 0, y = 0;
    
    for (int i = 0; i < arrSize; i++)
    {
        if(checkbit(arr[i],setBitNo))
            x ^= arr[i];
        else
            y ^= arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if(checkbit(i, setBitNo))
            x ^= i;
        else
            y ^= i;
    }

    x < y ? cout<<x<<" "<<y : cout<<y<<" "<<x;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int arrSize;
        cin>>arrSize;
        int arr[arrSize];
        for(int i = 0 ; i < arrSize; i++) cin>>arr[i];

        repeatedNumbers(arr, arrSize);

        cout<<"\n";
    }
    
    return 0;
}