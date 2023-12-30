#include<iostream>
#include <limits>
#include<vector>
#include<map>

using namespace std;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
int maxProfit1(vector<int>& prices){
    // TC : O(N)
    // SC : O(N)
    int maxProfit = 0;
    int n = prices.size();
    vector<int> maxPrices(n, 0);
    maxPrices[n-1] = prices[n-1];
    for(int i = n-2; i >= 0; i--){
        maxPrices[i] = max(maxPrices[i+1], prices[i]);
    }
    for(int i = 0; i < n; i++){
        maxProfit = max(maxProfit, maxPrices[i] - prices[i]);
    }

    return maxProfit;
}

int maxProfit2(vector<int>& prices) {
    // TC - O(N)
    // SC - O(1)
    int max_profit = 0;
    int n = prices.size();
    int minPrice = prices[0];
    for(int i = 1; i < n; i++){
        minPrice = min(minPrice, prices[i]);
        max_profit = max(max_profit, prices[i] - minPrice);
    }
    
    return max_profit;
}

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout<<maxProfit2(prices);
    return 0;
}