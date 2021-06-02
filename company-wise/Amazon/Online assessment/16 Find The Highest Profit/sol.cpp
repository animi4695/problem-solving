#include<iostream>
#include<unordered_map>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

int findProfit(vector<int> inventory, int order){
    // Bruteforce 
    priority_queue<int, vector<int>> pq;
    for(auto p : inventory){
        pq.push(p);
    }
    int profit = 0;
    while(order--){
        int stock = pq.top();
        pq.pop();
        profit += stock;
        pq.push(stock-1);
    }
    return profit;
}

// returns sum of arithmetic sequence from start to stop (exclusive).
int seqSum(int start, int stop) {
    return (start + stop - 1) * (stop - start) / 2;
}

// solution-2
int findProfit2(vector<int> inventory, int order){
    // montonically decreasing pattern. we can apply BS
    // TODO
}



int main(){
    vector<int> inventory = {6, 4};
    cout<<findProfit(inventory, 4);
}