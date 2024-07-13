#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int maximumUserTraffic(vector<int>& login, vector<int>& logout);

int main() {
    vector<int> login = {1,2,3};
    vector<int> logout = {10, 8, 4};

    int res = maximumUserTraffic(login, logout);

    cout<<res;

    return 0;
}

int maximumUserTraffic(vector<int>& login, vector<int>& logout) {
    int res = 0;
    // todo
    return res;
}

