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
unordered_map<char, int> ump;

bool mycmp(string& a, string& b) {
    for(int i = 0; i < min(a.size(), b.size()); i++) {
        if(ump[a[i]] != ump[b[i]]){
            return ump[a[i]] < ump[b[i]];
        }
    }

    return a.size() < b.size();
}

vector<string> sortProductCodes(string order, vector<string>& productCodes) {
    for(int i = 0; i < order.size(); i++) {
        ump[order[i]] = i;
    }

    sort(productCodes.begin(), productCodes.end(), mycmp);

    return productCodes;
}

int main() {
    string order = "abcdefghijklmnopqrstuvwxyz";
    vector<string> productCodes = {"adc", "abc"};
    
    vector<string> res = sortProductCodes(order, productCodes);
    for(auto r : res){
        cout<<r<<" ";
    }

    return 0;
}