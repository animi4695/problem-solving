#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

int getMaxRacers(vector<int>& speed, int k) {
    unordered_map<int, int> speedFreq;
    int max_racers = 0;
    int l = 0;
    for(int r = 0; r < speed.size(); r++){
        speedFreq[speed[r]]++;

        while(r - l + 1 - speedFreq[speed[r]] > k){
            // window has more than k removals.
            speedFreq[speed[l]]--;
            if(speedFreq[speed[l]] == 0){
                speedFreq.erase(speed[l]);
            }
            l++;
        }

        max_racers = max(max_racers, speedFreq[speed[r]]);
    }
    return max_racers;
}

int main() {
    vector<int> speed = {1,4,4,2,2,4};
    int k = 2;
    cout<<getMaxRacers(speed, k)<<"\n";

    return 0;
}