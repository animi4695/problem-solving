#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_map>

using namespace std;
int getDiscountPairs(int x, vector<int>& prices);
int main(){
    vector<int> prices =  {31, 25, 85, 29, 35};
    int x = 60;
    // Expected output = 3
    int res = getDiscountPairs(x, prices);
    cout<<res;
    return 0;
}

int getDiscountPairs(int x, vector<int>& prices){
    int res = 0;
    unordered_map<int, int> remFreq;
    for(auto price : prices) {
        int rem = price % x;
        remFreq[rem]++;
    }

    // when both the numbers in pair are exactly divisible by x (combinatorics formula nC2 = n*(n-1)/2)
    res += remFreq[0] * (remFreq[0] - 1) / 2;

    // for every remainder r, find the number of elements with remainder (x - r) using remFreq
    for (int i = 0; i <= x/2; i++){
        if(i == x - i){
            // special case when the remainders are same
            // element with this remainder can only form pairs among theselves
            res += remFreq[i] * (remFreq[i] - 1) / 2;
        } else {
            // count pairs with remainders i and x - i
            res += remFreq[i] * remFreq[x - i];
        }
    }

    return res;
}

