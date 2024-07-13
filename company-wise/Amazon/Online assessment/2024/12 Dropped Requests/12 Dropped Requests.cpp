#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

int ThrottlingGateway(int n, vector<int> &requestTime);

int main() {
    vector<int> requestTimes = {1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7};
    int n = requestTimes.size();

    int res = ThrottlingGateway(n, requestTimes);
    cout << res << " ";

    return 0;
}

int ThrottlingGateway(int n, vector<int> &requestTime) {

    // ref - https://hackmd.io/@mizugakun/H1mA50BZY
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (i > 2 && requestTime[i] == requestTime[i - 3]){
            cnt++;
        }
        else if (i > 19 && requestTime[i] - requestTime[i - 20] < 10){
            cnt++;
        }
        else if (i > 59 && requestTime[i] - requestTime[i - 60] < 60){
            cnt++;
        }
    }
    return cnt;
}