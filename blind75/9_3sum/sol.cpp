#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
// https://leetcode.com/problems/3sum

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i == 0 || nums[i] != nums[i - 1])
        {
            // two pointer approach
            int p1 = i + 1, p2 = nums.size() - 1;
            while (p1 < p2)
            {
                int sum = nums[i] + nums[p1] + nums[p2];
                if (sum < 0 || p1 > i + 1 && nums[p1] == nums[p1 - 1])
                    p1++;
                else if (sum > 0 || (p2 < nums.size() - 1 && nums[p2] == nums[p2 + 1]))
                {
                    p2--;
                }
                else
                {
                    res.push_back({nums[i], nums[p1], nums[p2]});
                    p1++;
                    p2--;
                }
            }
        }
    }

    return res;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int target = 0;
    threeSum(nums);
    return 0;
}