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
    // find max ele from logout.
    int maxele = *max_element(logout.begin(), logout.end());

    vector<int> traffic(maxele + 2, 0); // +2 because of 0 indexed, we add 1 more to mark logout[i] = 10 at index 11.
    // calculate traffic for each request
    // i.e Mark the login and logout of each request.
    for(int i = 0; i < login.size(); i++) {
        traffic[login[i]] += 1;
        traffic[logout[i] + 1] -= 1;
    }

    // Now that we have traffic, we need to find the max_traffic.
    int max_traffic = 0;
    int curr_traffic = 0;
    for(int i = 0; i <= maxele; i++){
        curr_traffic += traffic[i];
        max_traffic = max(max_traffic, curr_traffic);
    }

    // Now that we have max_traffic, we need to find number of days max_traffic happened
    curr_traffic = 0;
    for(int i = 0; i <= maxele; i++){
        curr_traffic += traffic[i];
        if(curr_traffic == max_traffic)
            res++;
    }
    return res;
}

