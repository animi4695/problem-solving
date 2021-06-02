#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int minSteps(vector<vector<char>>& grid);
int main(){
    vector<vector<char>> grid = {{'S', 'O', 'O', 'S', 'S'},
                                 {'D', 'O', 'D', 'O', 'D'},
                                 {'O', 'O', 'O', 'O', 'X'},
                                 {'X', 'D', 'D', 'O', 'O'},
                                 {'X', 'D', 'D', 'D', 'O'}
                                };
        cout<<minSteps(grid);
}

int minSteps(vector<vector<char>>& grid) {
    // BFS
    vector<vector<int>> dirs = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

    queue<pair<int, int>> q;

    // collect all the 'S' 
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == 'S'){
                q.push({i,j});
            }
        }
    }

    int steps = 0;
    while (!q.empty())
    {
        int sz = q.size();
        for(int i = 0; i < sz; i++){
            pair<int, int> p = q.front();
            q.pop();
            if(grid[p.first][p.second] == 'X')
                return steps;
            // mark as visited
            grid[p.first][p.second] = 'D';

            for(auto dir : dirs){
                int nx = p.first + dir[0];
                int ny = p.second + dir[1];
                if(nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || grid[nx][ny] == 'D')
                    continue;
                q.push({nx, ny});
            }
        }
        steps++;
    }
    return -1;
}