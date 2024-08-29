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

int getMaxConsecutiveON(const string& server_states, int k){
    vector<int> consecutive_len_list;
    
    char ch = server_states[0];
    int curr_len = 0;
    for(int i = 0; i < server_states.length(); i++) {
        if(server_states[i] == ch){
            curr_len++;
        }
        else{
            consecutive_len_list.push_back((ch == '0' ? -1 : 1) * curr_len);
            curr_len = 1;
            ch = server_states[i];
        }
    }
    consecutive_len_list.push_back((ch == '0' ? -1 : 1) * curr_len);

    int max_sum = 0;
    int sum = 0;
    int neg_count = 0;

    // sliding window
    int left = 0;
    for(int right = 0; right < consecutive_len_list.size(); right++) {
        if(consecutive_len_list[right] < 0){
            neg_count++;
        }
        sum += abs(consecutive_len_list[right]);
        while(neg_count > k) {
            if(consecutive_len_list[left] < 0){
                neg_count--;
            }
            sum -= abs(consecutive_len_list[left]);
            left++;
        }
        max_sum = max(max_sum, sum);
    }

    return max_sum;
}

int main() {
    string server_states = "00010";
    int k = 1;

    cout<<getMaxConsecutiveON(server_states, k)<<"\n";

    server_states = "1001";
    k = 2;
    cout<<getMaxConsecutiveON(server_states, k)<<"\n";

    server_states = "11101010110011";
    k = 2;
    cout<<getMaxConsecutiveON(server_states, k)<<"\n";

    return 0;
}