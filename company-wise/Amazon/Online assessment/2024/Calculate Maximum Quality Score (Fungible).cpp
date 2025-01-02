
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

long maxSubarraySum(vector<long>& arr) {
    long max_sum = LLONG_MIN, current_sum = 0;
    for (long val : arr) {
        current_sum = max(val, current_sum + val);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}
long calculateMaxQualityScore(int impactFactor, vector<int>& ratings) {
    int n = ratings.size();

    // Step 1: Compute max sum for original ratings
    vector<long> original(ratings.begin(), ratings.end());
    long maxOriginal = maxSubarraySum(original);

    // Step 2: Compute max sum for Amplify strategy
    vector<long> amplify(ratings.begin(), ratings.end());
    for (int i = 0; i < n; i++) {
        amplify[i] *= impactFactor; // Amplify the segment
    }
    long maxAmplify = maxSubarraySum(amplify);

    // Step 3: Compute max sum for Adjust strategy
    vector<long> adjust(ratings.begin(), ratings.end());
    for (int i = 0; i < n; i++) {
        if (adjust[i] > 0) {
            adjust[i] = floor(adjust[i] / (double)impactFactor); // Apply floor for positive values
        } else {
            adjust[i] = ceil(adjust[i] / (double)impactFactor);  // Apply ceil for negative values
        }
    }
    long maxAdjust = maxSubarraySum(adjust);

    // Step 4: Return the maximum of all scenarios
    return max(max(maxOriginal, maxAmplify), maxAdjust);
}

int main() {

    int impactFactor = 2;
    vector<int> ratings = {5, -3, -3, 2, 4};

    cout <<calculateMaxQualityScore(impactFactor, ratings) << endl;

    return 0;
}


// Imagine you're a seller on Amazon, specializing in eco-friendly products. Each of your items is rated by customers based on its quality and environmental impact.

// The overall qualityScore of your products is determined by the maximum possible sum of consecutive ratings.

// To improve the qualityScore of your products and attract more customers, you are given with an integer impactFactor and the following two strategies:

// Amplify Ratings: Select a contiguous segment of ratings and amplify them by multiplying each rating in that range by impactFactor.
// Adjust Ratings: Select a contiguous segment of ratings and adjust them by dividing each rating in that range by impactFactor
// Your task is to determine the maximum possible qualityScore for your eco-friendly products after applying exactly one of these strategies.

// Note: When applying the second strategy i.e., Adjust Ratings; For dividing positive ratings, floor the division result, and for dividing negative ratings, use the ceiling value of the division result,

// Example: Given ratings = [4, -5, 5, -7, 1], and impactFactor = 2. If we choose to apply the second strategy with segment [2, 5] (Assuming 1-based indexing) then, modified ratings: [4, ceil(-5/2), floor(5/2 [I think it should be 5/2 instead of S / 2], ceil(-7/2), floor(1/2)] = [4, -2, 2, -3, 0]. Note that the ceil(-7/2) = -3 and floor(5/2) = 2,

// Given an array of ratings of size n and an integer impactFactor, determine the maximum possible qualityScore i.e., maximum possible sum of consecutive ratings by optimally selecting exactly one of the strategies to modify the ratings.

// Function Description

// Complete the function calculateMaxQualityScore in the editor below

// calculateMaxQualityScore has the following parameters:

// int impactFactor: the value used in the strategies to amplify or adjust ratings.
// int ratings[n]: an array representing the ratings of eco-friendly products
// Returns

// long: the maximum possible qualityScore of your eco-friendly products after applying exactly one of the strategies.

// Possible solution hint -> Basically, if the array is not entirely negative, find the max sum subarray and multiply it by the factor. If the array is entirely negative, find the single largest negative number and divide it by the factor.

// 🐳 Hello spike! Thanks for carrying~ 💪

// Example 1:

// Input:  impactFactor = 2, ratings = [5, -3, -3, 2, 4]
// Output: 12 
// Explanation:

// Let's try both the strategies with different contiguous ranges to get the maximum qualityScore:



// If we perform the first strategy on the subsegment [4, 5] (1-based indexing), we get the ratings = [5, -3, -3, 4, 8] with a qualityScore of 12, which is the maximum qualityScore.

// Hence, the answer is 12.

      
// Constraints:
// 1 <= n <= 2 * 10^5
// 1 <= impactFactor <= 10^4
// -10^5 <= ratings[i] <= 10^5