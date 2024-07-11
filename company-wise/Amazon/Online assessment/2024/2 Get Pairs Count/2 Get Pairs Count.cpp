#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_set>

using namespace std;
int getPairsCount(vector<int>& process, int k);
int main(){
    vector<int> arr =  {7, 10, 13, 11};
    int k = 3;
    int res = getPairsCount(arr, k);
    cout<<res;
    return 0;
}

int getPairsCount(vector<int>& process, int k){
    // approach
    //          sort the array to make it easier to compare adjacent elements
    //          use two pointer approach to find the pairs
    int n = process.size();
    int count = 0;
    sort(process.begin(), process.end());
    // todo
    for(int i = 0; i < process.size(); i++) {
        // two pointer approach
        int r = process.size() - 1;
        while(r > i) {
            if(process[r] - process[i] <= k) {
                count += r - i;
                break;
            }
            else
                r--;
        }
    }
    return count;
}

