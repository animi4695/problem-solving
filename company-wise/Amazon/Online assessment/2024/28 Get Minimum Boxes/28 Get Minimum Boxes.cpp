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

int reduceGifts(vector<int>& prices, int k, int threshold) {
    int res = 0;
    if(prices.size() < k)
        return 0;

    sort(prices.begin(), prices.end(), greater<>());
    int windowSum = 0;

    for(int i = 0; i < k - 1; i++) {
        windowSum += prices[i];
    }
    
    for(int i = k - 1; i < prices.size(); i++) {
        windowSum += prices[i];
        if(windowSum > threshold){
            res++;
            windowSum -= prices[i - k + 1];
        }
        else {
            break;
        }
    }
    return res;
}

int main() {
    int k = 3;
    int threshold = 14;
    vector<int> prices = {3, 2, 1, 4, 6, 5};
    
    int res = reduceGifts(prices, k, threshold);
    cout<<res<<"\n";
    return 0;
}