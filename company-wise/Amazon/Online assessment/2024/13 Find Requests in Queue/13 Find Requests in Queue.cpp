#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;
vector<int> findRequestsInQueue(vector<int>& wait);
vector<int> findRequestsInQueue2(vector<int>& wait);

int main() {
    vector<int> wait = {2,2,3,1};

    vector<int> res = findRequestsInQueue2(wait);
    for(auto r : res){
        cout << r << " ";
    }

    return 0;
}

vector<int> findRequestsInQueue(vector<int>& wait) {
    // bruteforce
    int n = wait.size();
    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++)
        q.push({i, wait[i]});
    
    int time = 0;
    vector<int> res;
    while(!q.empty()) {
        int size = q.size();
        res.push_back(size);

        // process first req
        q.pop();

        queue<pair<int, int>> q_temp;
        while(!q.empty()) {
            auto ele = q.front();
            q.pop();

            if(ele.second > time + 1){
                q_temp.push({ele.first, ele.second});
            }
        }
        q = q_temp;
        time++;
    }

    res.push_back(0);
    return res;
}