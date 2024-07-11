#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_map>

using namespace std;
int getMaximaCount(string categories);
int getMaximaCount2(string categories);
int main(){
    string categories = "bccaaacb";
    // Expected output = 6
    int res = getMaximaCount2(categories);
    cout<<res;
    return 0;
}

int getMaximaCount(string categories) {
   int res = 0;
   vector<int> freq(26, 0);
    
    // how many times a character is maximum freq in the prefix of the string 
    vector<int> maximumCount(26, 0);
    // maximum Freq
    int maxFreq = 0;

    // for each character in the string, find the maximum freq.
    for (char c : categories) {
        int index = c - 'a';
        freq[index]++;
        maxFreq = max(maxFreq, freq[index]);
        
        // if the freq of the character is maximum, increment the count of the character
        for (int i = 0; i < 26; i++) {
            if (freq[i] == maxFreq) {
                maximumCount[i]++;
            }
        }
    }
    

    for(int i = 0; i < 26; i++){
        res = max(res, maximumCount[i]);
    }

    return res;
}

int getMaximaCount2(string categories) {
    vector<vector<int>> dp(26, vector<int>(categories.size(), 0));

    dp[categories[0] - 'a'][0] = 1;
    for(int i = 1; i < categories.size(); i++){
        for(int j = 0; j < 26; j++){
            dp[j][i] = dp[j][i-1] + (j == categories[i] - 'a' ? 1 : 0);
        }
    }

    // for each char in categories, find the maximum in dp from a to z. update the res of that char
    vector<int> res(26, 0);
    for(int i = 0; i < categories.size(); i++){
        int maxFreq = 0;
        for(int j = 0; j < 26; j++){
            maxFreq = max(maxFreq, dp[j][i]);
        }

        for(int j = 0; j < 26; j++){
            if(dp[j][i] == maxFreq){
                res[j]++;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 26; i++){
        ans = max(ans, res[i]);
    }

    return ans;
}

