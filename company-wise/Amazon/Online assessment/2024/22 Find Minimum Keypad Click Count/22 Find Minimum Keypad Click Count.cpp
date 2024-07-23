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

int findMinimumKeypadClickCount(string letters) {
   vector<int> count(26, 0);
   for(auto letter: letters) {
    count[letter - 'a']++;
   }

   sort(count.begin(), count.end(), greater<int>());
   int ans = 0;
   int k = 1; // k represents the order in which we are placing keys. 
   // eg. if we are filling second place of a 1 or 2 or ... then k = 2
   for(int i = 1; i <= 26; i++){
    ans += k * count[i - 1];
    if(i % 9 == 0) {
        // increment the row, every time we fill 9 digits.
        k++;
    }
   }
   return ans;
}

int main() {
    string letters = "abacadefghibj";
    // output = 14
    cout<<findMinimumKeypadClickCount(letters)<<"\n";

    return 0;
}