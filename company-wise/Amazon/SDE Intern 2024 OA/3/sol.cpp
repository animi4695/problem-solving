#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<climits>
#include<unordered_map>

using namespace std;

int main(){
    vector<int> comedyReleaseTime = {1, 4};
    vector<int> comedyDuration = {3, 2};
    vector<int> dramaReleaseTime = {5, 2};
    vector<int> dramaDuration = {2, 2};


    int res = MinimumTimeSpent(comedyReleaseTime, comedyDuration, dramaReleaseTime, dramaDuration);
    cout<<res<<endl;

    return 0;
}

int MinimumTimeSpent(vector<int> comedyReleaseTime, vector<int> comedyDuration, vector<int> dramaReleaseTime, vector<int> dramaDuration){
    int res = INT_MAX;
    int x, y;
    for(int i = 0; i < comedyDuration.size(); i++){
        comedyDuration[i] += comedyReleaseTime[i];
        x = min(x, comedyDuration[i]);
    }
    for(int i = 0; i < dramaDuration.size(); i++){
        dramaDuration[i] += dramaReleaseTime[i];
        y = min(y, dramaDuration[i]);
    }

    for(int i = 0; i < comedyDuration.size(); i++){
        res = min(res, max(x, comedyReleaseTime[i]) + comedyDuration[i] - comedyReleaseTime[i]);
    }
    for(int i = 0; i < dramaDuration.size(); i++){
        res = min(res, max(y, dramaReleaseTime[i]) + dramaDuration[i] - dramaReleaseTime[i]);
    }
    return res;
}