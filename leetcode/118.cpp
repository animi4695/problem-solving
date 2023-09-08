#include<iostream>
#include <limits>
#include<vector>
#include<map>

using namespace std;
class Solution {
public:
    // link - https://leetcode.com/problems/pascals-triangle/description/
    // TC - O(N^2)
    // SC - O(N^2)
    // N - NumRows
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});

        for (int i = 1; i < numRows; i++){
            vector<int> curr(i+1, 1);
            
            for(int j = 1; j < i; j++){
                // prev_row = [1, 2, 1]
                // curr_row = [1, _, 1]
                // _ can be calculated by using previous row
                curr[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(curr);
        }
        return res;
    }
};