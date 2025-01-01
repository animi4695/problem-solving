// You are given a 2D array. Your task is to find the regional maxima in the array and return a 2D array of size (X * 2) where each row contains the position [i, j] of a regional maximum.

// Definition of Regional Maximum:

// A cell (i, j) is considered a regional maximum if:

// array[i][j] != 0
// array[i][j] is the maximum value within its region.
// Definition of Region:

// For a cell (i, j) with value cell:

// The region is defined as the rectangular area (i - cell to i + cell) * (j - cell to j + cell).
// Exclude the corner cells from above: (i - cell, j - cell), (i - cell, j + cell), (i + cell, j - cell) and (i + cell, j + cell).
// If the calculated region goes out of bounds, ignore those out-of-bound cells.
// Function Description

// Complete the function findRegionalMaxima in the editor.

// findRegionalMaxima has the following parameter:

// int[][] array: a 2D array of integers
// Returns

// int[][]: a 2D array where each row contains the position [i, j] of a regional maximum

// Example 1:

// Input:  array = [[3, 0, 1], [2, 0, 0], [0, 0, 0]]
// Output: [[0, 0], [0, 2]] 
// Explanation:
// The given 2D array is:
//       [
//         [3, 0, 1],
//         [2, 0, 0],
//         [0, 0, 0],
//       ]
    
// The cell at position [0, 0] with value 3 is a regional maximum because:    
        
// It is not 0.
        
// Its region is from [0, 0] to [3, 3] (excluding corners and out-of-bounds), and it is the maximum in this region.
// The cell at position [0, 2] with value 1 is a regional maximum because:
            
// It is not 0.
        
// Its region is from [0, 1] to [1, 3] (excluding corners and out-of-bounds), and it is the maximum in this region. 
// Therefore, the output is [[0, 0], [0, 2]].



#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<vector<int>> findRegionalMaxima(vector<vector<int>> array) {

}

int main(){
    vector<vector<int>> array = {};
    vector<vector<int>> ans = findRegionalMaxima(array);
    return 0;
}
