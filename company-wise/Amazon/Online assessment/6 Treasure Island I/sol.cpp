#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int minSteps(vector<vector<char>>& grid);
int main(){
    vector<vector<char>> grid = {{'O', 'O', 'O', 'O'},
                                 {'D', 'O', 'D', 'O'},
                                 {'O', 'O', 'O', 'O'},
                                 {'X', 'D', 'D', 'O'}
                                };
        cout<<minSteps(grid);
}

int minSteps(vector<vector<char>>& grid){
    // BFS
    vector<vector<int>> dirs = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

    queue<pair<int, int>> q;
    q.push({0,0});
    grid[0][0] = 'D'; // mark as visited
    int steps = 1;
    while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; i++){
            pair<int, int> pos = q.front();
            q.pop();
            for(auto dir : dirs){
                int nx = pos.first + dir[0];
                int ny = pos.second + dir[1];
                // boundary check
                if(nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || grid[nx][ny] == 'D')
                    continue;
                if(grid[nx][ny] == 'X')
                    return steps;
                q.push({nx, ny});
                // mark as visited
                grid[nx][ny] = 'D';
            }
        }
        steps++;
    }
    return -1;
}