#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>

using namespace std;
// https://leetcode.com/problems/product-of-array-except-self/

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> res(nums.size(), 1);
    int left = 1;
    int right = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        left = left * nums[i - 1];
        res[i] = res[i] * left;
    }
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        right = right * nums[i + 1];
        res[i] = res[i] * right;
    }
    return res;
}

int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    productExceptSelf(nums);
    return 0;
}