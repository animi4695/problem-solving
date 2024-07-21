#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

int getMinNumMoves(std::vector<int>& blocks) {
    int n = blocks.size();
    int minIndex = 0, maxIndex = 0;
    
    // Find the index of the lightest block and the heaviest block
    for (int i = 1; i < n; ++i) {
        if (blocks[i] < blocks[minIndex]) {
            minIndex = i;
        }
        if (blocks[i] > blocks[maxIndex]) {
            maxIndex = i;
        }
    }
    
    // Calculate the number of swaps needed
    int swaps = minIndex + (n - 1 - maxIndex);
    
    // If the lightest block is to the right of the heaviest block, we need one less swap
    if (minIndex > maxIndex) {
        --swaps;
    }
    
    return swaps;
}

int main() {
    vector<int> blocks = {2,4,3,1,6};
    cout<<getMinNumMoves(blocks)<<"\n";
    
    blocks = {4, 11, 9, 10, 12};
    cout<<getMinNumMoves(blocks)<<"\n";
    
    blocks = {3,2,1};
    cout<<getMinNumMoves(blocks)<<"\n";


    return 0;
}