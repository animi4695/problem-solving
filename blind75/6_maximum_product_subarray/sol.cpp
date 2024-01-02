#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>

using namespace std;
// https://leetcode.com/problems/maximum-product-subarray/
// solution
// https://www.youtube.com/watch?v=hnswaLJvr6g
int maxProduct(vector<int> &nums)
{
    // intuitive
    // all +ve => multiply everything
    // even -ve, rest +ve => multiply everything
    // odd -ve, rest +ve => remove each -ve and multiply everything. find which ans is max when -ve is removed
    //          eg. [2, 3, -1, 4, -3, 3, -3, 8]
    //              if -1 is removed, answer can be max of multiplication of [2, 3] or [4, -3, 3, -3, 8]
    // edge case if contains = 0 => skip it and reset the prod to 1

    int ans = INT_MIN;
    int prefix = 1, suffix = 1;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;

        prefix = prefix * nums[i];
        suffix = suffix * nums[n-i-1];

        ans = max(ans, max(prefix, suffix));
    }

    return ans;
}
int main()
{
    vector<int> nums = {2, 3, -2, 4};
    maxProduct(nums);
    return 0;
}