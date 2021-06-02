#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<vector<int>> graph(n);
    for (auto &edge : connections)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    vector<int> low(n, -1);
    vector<int> disc(n, -1);
    vector<int> parent(n, -1);

    vector<vector<int>> res;
    int counter = 0;
    dfs(graph, low, disc, parent, res, 0, counter);

    return res;
}

void dfs(vector<vector<int>> &graph, vector<int> &low, vector<int> &disc, vector<int> &parent, vector<vector<int>> &res, int u, int &counter)
{
    disc[u] = low[u] = counter++;

    // neighbours
    for (auto &v : graph[u])
    {
        if (parent[u] == v)
            continue;
        if (disc[v] == -1)
        {
            parent[v] = u;
            dfs(graph, low, disc, parent, res, v, counter);

            if (low[v] > disc[u])
                res.push_back({u, v});
        }
        low[u] = min(low[u], low[v]);
    }
}