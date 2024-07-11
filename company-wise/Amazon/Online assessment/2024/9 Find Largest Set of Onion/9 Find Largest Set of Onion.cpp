#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_set>

using namespace std;

int findLargestSetOnion(int i, vector<int>& onionBags);

int main(){
    vector<int> onionBags = {3, 9, 4, 2, 16};
    // Expected output = 3

    sort(onionBags.begin(), onionBags.end());
    int res = -1;
    for(int i = 0; i < onionBags.size(); i++){
        int ans = 1 + findLargestSetOnion(0, onionBags);
        res = max(res, ans);
    }
    cout<<res<<" ";
    return 0;
}

int findLargestSetOnion(int i, vector<int>& onionBags) {
    if(i == onionBags.size()-1)
        return 0;
    
    int ans = -1;
    for(int j = i + 1; j < onionBags.size(); j++){
        if(onionBags[i] * onionBags[i] == onionBags[j]){
            int d = findLargestSetOnion(j, onionBags);
            ans = max(ans, 1 + d);
        }
    }

    return ans;
}
