#include<iostream>
#include<unordered_map>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main() {

}

int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{
    sort(boxTypes.begin(), boxTypes.end(), mycmp);
    int i = 0;
    int res = 0;
    while(i < boxTypes.size() && truckSize > 0){
        int x = min(boxTypes[i][0], truckSize);
        res += x*boxTypes[i][1];
        truckSize -= x;
        i++;
    }
    return res;
}

static bool mycmp(vector<int>& a, vector<int>& b){
    return a[1] > b[1]; // sort according to number of units value
}