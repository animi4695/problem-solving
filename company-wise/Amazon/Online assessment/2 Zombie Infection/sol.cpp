#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int minNumOfDays(vector<vector<int>>& grid);

int main() {
    vector<vector<int>> grid = { { 0, 1, 1, 0, 1 }, { 0, 1, 0, 1, 0 }, { 0, 0, 0, 0, 1 }, { 0, 1, 0, 0, 0 } };
    cout<<minNumOfDays(grid)<<"\n";
}

int minNumOfDays(vector<vector<int>>& grid){
    // BFS
    int n = grid.size(), m = grid[0].size();
    int res = 0;
    if(n == 0 || m == 0)
        return -1;
    
    int target = n*m;
    int cnt = 0;
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                q.push({i, j});
                cnt++;
            }
        }
    }

    vector<vector<int>> dirs = {{0,1}, {0, -1}, {-1, 0}, {1,0}};
    while(!q.empty()){
        int sz = q.size();
        if(cnt == target){
            return res;
        }
        for(int i = 0; i < sz; i++){
            pair<int, int> curr = q.front();
            q.pop();
            for(int d = 0; d < 4; d++){
                int ni = curr.first + dirs[d][0];
                int nj = curr.second + dirs[d][1];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 0){
                    cnt++;
                    grid[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }
        res++;
    }
    return -1;
}