#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

// Note - Not sure if the question is correct

int minIncrements(vector<int>& power) {
    int ans = 0;
    for(int i = 1; i < power.size(); i++) {
        if(power[i] < power[i-1]){
            int increment = power[i-1] - power[i];
            power[i] += increment;
            ans += increment;
        }
    }
    return ans;
}

int main() {
    vector<int> power = {3,4,1,6,2};
    // output = 7
    cout<<minIncrements(power)<<"\n";

    return 0;
}