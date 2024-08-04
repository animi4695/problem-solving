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

struct custCmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if(a.first == b.first)
            return a.second > b.second; // Comparing by server ID, if loads are equal
        return a.first > b.first; // comparing by number of requests
    }
};

vector<int> getServerId(int num_servers, vector<int>& requests) {
    vector<int> sar(num_servers);
    vector<int> res;

    priority_queue<pair<int, int>, vector<pair<int,int>>, custCmp> pq; // (load, serverid) 
    for(int i = 0; i < num_servers; i++) {
        pq.push({0, i});
    }

    for(auto req : requests) {
        // pop the server with lowest load from pq
        auto min_server = pq.top();
        pq.pop();

        // if the min_server has serverid greater than current req.
        // search for next best one.
        vector<pair<int, int>> temp;
        if(min_server.second > req) {
            while(!pq.empty() && pq.top().second > req){
                temp.push_back(pq.top());
                pq.pop();
            }
            temp.push_back(min_server);
            min_server = pq.top();
            pq.pop();
        }

        res.push_back(min_server.second);
        min_server.first++;

        pq.push(min_server);

        // insert left out temp ones.
        for(auto server: temp) {
            pq.push(server);
        }
    }
    return res;
}

int main() {
    int num_servers = 5;
    vector<int> requests = {4,0,2,2};

    vector<int> res = getServerId(num_servers, requests);
    for(auto r : res) {
        cout<<r<<" ";
    }
    return 0;
}