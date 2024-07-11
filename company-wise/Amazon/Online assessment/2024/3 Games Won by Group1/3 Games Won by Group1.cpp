#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_set>

using namespace std;
int countWins(int n, vector<int>& group1, vector<int>& group2);
int main(){
    vector<int> group1 =  {1,2,3};
    vector<int> group2 =  {3,2,1};
    int n = 3;
    // Expected output = 1
    int res = countWins(n, group1, group2);
    cout<<res;
    return 0;
}

int countWins(int n, vector<int>& group1, vector<int>& group2){
    int res = 0;
    // calculate diff
    vector<int> diff;
    for(int i = 0; i < n; i++){
        diff.push_back(group1[i] - group2[i]);
    }

    // sort diff
    sort(diff.begin(), diff.end());

    // calculate wins by group1
    for(int i = 0; i < n; i++) {
        // for every index i in diff, find the second index j such that diff[i] + diff[j] > 0 using binary search
        auto it = upper_bound(diff.begin(), diff.end(), -diff[i]);
        int j = distance(diff.begin(), it);
        // max(j, i + 1) gives the number of elements greater than -diff[i] in diff array from index i + 1 to n - 1
        res += n - max(j, i + 1); // number of elements greater than max(diff[i], diff[j])
    }
    return res;
}

