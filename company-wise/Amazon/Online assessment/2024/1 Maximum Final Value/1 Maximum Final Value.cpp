#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_set>

using namespace std;
int maxFinalValue(vector<int>& arr);
int main(){
    vector<int> arr =  {3, 1, 3, 4};
    int res = maxFinalValue(arr);
    cout<<res;
    return 0;
}

int maxFinalValue(vector<int>& arr){
    // approach
    //          sort the array to make it easier to compare adjacent elements
    //          if the first element is not 1, make it 1
    //          for all the elements from index 2....n -> if curr element is greater prev_ele + 1. modify it.
    int n = arr.size();
    sort(arr.begin(), arr.end());

    if(arr[0] != 1)
        arr[0] = 1;

    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i-1] + 1)
            arr[i] = arr[i-1] + 1;
    }

    return arr[n-1];
}