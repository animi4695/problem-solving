#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int numPairsDivisibleBy60_1(vector<int> &time){
    // Bruteforce
    int ans = 0;
    for (int i = 0; i < time.size(); i++)
    {
        for (int j = i + 1; j < time.size(); j++)
        {
            if ((time[i] + time[j]) % 60 == 0)
                ans++;
        }
    }
    return ans;
}

int numPairsDivisibleBy60_2(vector<int>& time) {
    // optmised
    // (a+b)%60 = 0
    // ((a%60) + (b%60))%60 = 0

    vector<int> remainders(60, 0);
    int count = 0;
    for(int t : time){
        if(t%60 == 0){
            // check if a%60 == 0 && b%60 == 0
            count += remainders[0];
        }
        else{
            // check if a%60 + b%60 = 60
            count += remainders[60-t%60];
        }
        remainders[t%60]++;
    }
    return count;
}

int main(){

}