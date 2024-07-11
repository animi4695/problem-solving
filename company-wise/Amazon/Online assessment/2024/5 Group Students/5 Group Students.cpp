#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_map>

using namespace std;
int groupStudents(int maxSpread, vector<int>& levels);

int main(){
    vector<int> levels =  {1,4,7,3,4};
    int maxSpread = 2;
    // Expected output = 3
    int res = groupStudents(maxSpread, levels);
    cout<<res;
    return 0;
}

int groupStudents(int maxSpread, vector<int>& levels){
    int res = 1; // 1 because we start with group 1.
    // sort the levels to make sure our grouping elements are nearby.
    sort(levels.begin(), levels.end());

    // maintain the starting element of each group we build.
    int group_start = levels[0];
    for(int i = 1; i < levels.size(); i++){
        // if the current element is more than maxSpread away from the group_start, 
        // we need to start a new group.
        if(levels[i] - group_start > maxSpread){
            res++;
            group_start = levels[i];
        }
    }
    return res;
}

