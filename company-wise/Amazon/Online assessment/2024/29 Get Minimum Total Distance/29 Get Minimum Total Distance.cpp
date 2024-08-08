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

int median(vector<int>& arr, int start, int end) {
    int length = end - start + 1;
    if(length % 2 == 0){
        return (arr[start + length / 2 - 1] + arr[start + length/2]) / 2;
    }
    else{
        return arr[start + length / 2];
    }
}

int getMinTotalDistance(vector<int>& dist_centers) {
    int res = INT_MAX;
    sort(dist_centers.begin(), dist_centers.end());
    // to place 2 warehouses. we want to divide the dist_centers
    // into 2 equal half parts, so that the distance between each dist_center and the
    // warehouse is minimum.

    // to find the best half, we try every index as half and get the median (center) for each half to place the warehouse.
    // once we place warehouse, calculate the distance between each dist_center and median. take the closest distance and add it to total distance.
    for(int i = 1; i < dist_centers.size(); i++) {
        int median1 = median(dist_centers, 0, i - 1);
        int median2 = median(dist_centers, i, dist_centers.size() - 1);

        int currDistanceSum = 0;
        for(int center : dist_centers) {
            int distToClosestWarehouse = min(abs(center - median1), abs(center - median2));
            currDistanceSum += distToClosestWarehouse;
        }

        res = min(res, currDistanceSum);
    }
    return res;
}

int main() {
    vector<int> dist_centers = {1,2,3};
    
    int res = getMinTotalDistance(dist_centers);
    cout<<res<<"\n";
    return 0;
}