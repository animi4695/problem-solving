#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <cmath>
#include <string>

using namespace std;



int findMinimumOperations(string image) {
   int j = image.length()-1;
   int commonLength = 0;
   for(int i = 0; i < image.length(); i++) {
    if(image[i] == image[j]){
        j--;
        commonLength++;
    }
   }

   int ans = image.length() - commonLength;
   return ans;
}

int main() {
    string image = "0100110";
    // output = 3
    cout<<findMinimumOperations(image)<<"\n";

    return 0;
}