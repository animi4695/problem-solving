#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<climits>
#include<unordered_map>
#include<queue>

using namespace std;

int balanceString(string s);

int balanceString(string s){
    unordered_map<int, int> count;
    int n = s.size();
    int res = n;
    int k = n / 4;
    int i = 0;
    for (int j = 0; j < n; j++){
        count[s[j]]++;
    }
    // B,D,U,H
    for (int j=0;j<n;j++){
        count[s[j]]--;
        while(i < n && count['B'] <= k && count['D'] <= k && count['U'] <= k && count['H'] <= k){
            res = min(res, j - i + 1);
            count[s[i++]]++;
        }
    }
    return res;
}
int main() {
    cout << balanceString("HBBBUBBB") << endl; // 5
    return 0;
}