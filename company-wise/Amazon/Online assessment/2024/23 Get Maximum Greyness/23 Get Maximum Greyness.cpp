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

int getMaximumGreyness(vector<string>& pixels) {
    int n = pixels.size();
    int m = pixels[0].size();
    int maxGreyness = INT_MIN;
    
    vector<int> black_row_count(n, 0);
    vector<int> black_col_count(m, 0);

   for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j){
        if(pixels[i][j] == '1'){
            black_row_count[i]++;
            black_col_count[j]++;
        }
    }
   }

   // calculate greyness for each cell and find max greyness
   for(int i = 0; i < n; ++i) {
    for(int j = 0 ; j < m; ++j){
        int blackInRow = black_row_count[i];
        int blackInCol = black_col_count[j];
        int whiteInRow = m - blackInRow;
        int whiteInCol = n - blackInCol;

        int greyness = blackInRow + blackInCol - whiteInRow - whiteInCol;
        maxGreyness = max(maxGreyness, greyness);
    }
   }
   return maxGreyness;
}

int main() {
    vector<string> pixels = {"1010", "0101", "1010"};
    // output = 1
    cout<<getMaximumGreyness(pixels)<<"\n";

    return 0;
}