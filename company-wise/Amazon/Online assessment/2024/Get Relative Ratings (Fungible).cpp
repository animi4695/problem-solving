#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

vector<long long> getRelativeRatings(vector<int> skill, vector<int> rating, int k) {

    int n = skill.size();

    vector<long long> ans(n, 0);

    vector<tuple<int, int, int>> players;
    for(int i = 0; i < n; i++){
        players.push_back({skill[i], rating[i], i});
    }

    sort(players.begin(), players.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    long long sumRatings = 0;
    for(int i = 0 ; i < n; i++) {
        int skill_i = get<0>(players[i]);
        int rating_i = get<1>(players[i]);
        int original_i = get<2>(players[i]);

        ans[original_i] = sumRatings;

        pq.push(rating_i);
        sumRatings += rating_i;

        if(pq.size() > k){
            sumRatings -= pq.top(); // remove smallest rating in heap
            pq.pop();
        }
    }

    return ans;
}

int main() {
    vector<int> skill = {1,2,3,4};
    vector<int> rating = {40, 30, 20, 10};
    int k = 2;

    // Compute relative ratings
    vector<long long> result = getRelativeRatings(skill, rating, k);

    // Print the output
    for (long long val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// One of the games launched on Amazon game has come up with a unique rating system for the players. It is based on their relative skill levels and absolute ratings.

// There are n players where the ith player has a skill level of skill[i] and an absolute rating of rating[i]. The relative rating of the ith player is defined as the maximum possible sum of ratings of at most k players with a skill level less than skill[i]. For example, if skill = [1, 2, 3, 4], rating = [40, 30, 20, 10] and k = 2, then the maximum possible sums of ratings of any two players with skill levels less than the player in consideration are [0, 40, 70, 70].

// Given skill, rating and k, find each player's relative rating.

// Function Description

// Complete the function getRelativeRatings in the editor.

// getRelativeRatings takes the following arguments:

// int skill[n]: The skills of the players
// int rating[n]: The absolute rating of the players
// int k: The number of top skills to consider for relative rating
// Returns

// long int[n]: The relative ratings of the players

// Example 1:

// Input:  skill = [1, 7, 5], rating = [0, 0, 1], k = 1
// Output: [0, 1, 0] 
// Explanation:


   

// With k = 1, choose one maximum skill level less than the current one. 

// No skill level is less than 1.
// For skill lelvel 7, skill level 5 and 1 are lower but only 5 has a relative rating > 0.
// The only skill level less is 1 with a rating of 0.

// Hence the answer is [0, 1, 0].

      
// Constraints:
// 1 ≤ n ≤ 2 * 10^5
// 0 ≤ k ≤ n - 1
// 1 ≤ skill[i] ≤ 10^9
// 1 ≤ rating[i] ≤ 10^9