#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows == 0)
            return rows;
        int cols = grid[0].size();
        int islands = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    markIslands(grid, i, j, rows, cols);
                    islands++;
                }
            }
        }
        return islands;
    }

    void markIslands(vector<vector<char>>& grid, int i, int j, int rows, int cols){
        // boundary check
        if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != '1')
            return;
        grid[i][j] = '2'; // mark as visited
        // spawn 4 direction check
        markIslands(grid, i, j + 1, rows, cols); 
        markIslands(grid, i, j - 1, rows, cols); 
        markIslands(grid, i - 1, j, rows, cols);
        markIslands(grid, i + 1, j, rows, cols); 
    }
};