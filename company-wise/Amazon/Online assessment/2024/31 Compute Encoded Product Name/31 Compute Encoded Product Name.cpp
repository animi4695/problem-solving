#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <map>
#include <cmath>
#include <string>
#include<climits>

using namespace std;

string computeEncodedProductName(string nameString) {
    map<char, int> mp;
    for(auto ch : nameString) {
        mp[ch]++;
    }

    int n = nameString.length();
    string res = nameString;
    int l = 0, r = nameString.length() - 1;
    if(n%2 != 0) {
        // odd string
        int mid = n/2;
        res[mid] = nameString[mid];
        mp[nameString[mid]]--;
    }

    for(auto m : mp) {
        char ch = m.first;
        int count = m.second;

        for(int i = 0; i < count / 2; i++) {
            res[l++] = ch;
            res[r--] = ch;
        }
    }

    return res;

}

int main() {
    string nameString = "yxxy";

    cout<<computeEncodedProductName(nameString)<<"\n";

    return 0;
}