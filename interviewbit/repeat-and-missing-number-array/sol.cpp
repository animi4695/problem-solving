#include<iostream>
#include <limits>
#include<vector>

using namespace std;
bool checkbit(int n, int i){
    return (n>>i)&1;
}

vector<int> findrepeatedNumber(vector<int>& arr, int N) {
    int XOR = arr[0];
    for (int i = 1; i < N; i++) XOR ^= arr[i];
    for (int i = 1; i <= N; i++) XOR ^= i;
    
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
    for (int i = 0; i < N; i++)
    {
        if(checkbit(arr[i],setBitNo))
            x ^= arr[i];
        else
            y ^= arr[i];
    }

    for (int i = 1; i <= N; i++)
    {
        if(checkbit(i, setBitNo))
            x ^= i;
        else
            y ^= i;
    }

    // linear seach to differentiate repeated and missing number.
    for(auto a : arr){
        if(a == x){
            return {x,y};
        }
    }
    return {y,x};
}
int main(){
    vector<int> arr = {3,1,2,5,3};
    findrepeatedNumber(arr, arr.size());
    return 0;
}