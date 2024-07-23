#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <cmath>
#include <string>
#include<climits>

using namespace std;

long long getTotalDist(vector<int>& centers, int mid){
    long long total = 0;
    for(int i = 0; i < centers.size(); i++){
        total += 2 * abs(centers[i] - mid);
    }
    return total;
}

int suitableLocations(int d, vector<int>& centers) {
    int first = -1;
    bool found = false;
    int lo = -1e9, hi = 1e9;
    
    // find the left most suitable warehouse locations
    while(lo <= hi) {
        int mid = lo + (hi-lo)/2;
        long long dist = getTotalDist(centers, mid);
        long long dist1 = getTotalDist(centers, mid+1);

        if(dist <= d){
            // found a suitable location. store and look for a better one.
            found = true;
            first = mid;
            hi = mid-1;
        }
        else if(dist < dist1){
            // dist, dist1 check is used to compensate -ve to +ve range.
            // There can be a scenario dist is greater than dist1 due to negatives in range.
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }

    if(!found)
        return 0;

    // find the right most suitable warehouse locations.
    lo = first; hi = 1e9;
    int last = -1;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        long long dist = getTotalDist(centers, mid);
        long long dist1 = getTotalDist(centers, mid+1);

        if(dist <= d){
            last = mid;
            lo = mid+1;
        }
        else if(dist < dist1){
            hi = mid-1;
        }
        else{
            lo = mid + 1;
        }
    }

    return last-first+1;
}

int main() {
    int d = 8;
    vector<int> centers = {-2, 1, 0};
    // output - 3
    int res = suitableLocations(d, centers);
    cout<<res;
    
    return 0;
}