#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>

using namespace std;
// https://leetcode.com/problems/maximum-subarray/

int maxSubArray(vector<int> &nums)
{
    // kadane's algorithm
    // TC - O(N)
    // SC - O(1)
    int currMax = 0, maxTillNow = INT_MIN;
    for(auto num : nums){
        currMax = max(num, currMax + num);
        maxTillNow = max(maxTillNow, currMax);
    }
    return maxTillNow;
}
int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    maxSubArray(nums);
    return 0;
}