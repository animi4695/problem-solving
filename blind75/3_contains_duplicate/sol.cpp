#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>

using namespace std;
// https://leetcode.com/problems/contains-duplicate/

bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int, int> umap;
    for (auto num : nums)
    {
        if (umap.find(num) != umap.end())
            return true;
        umap[num]++;
    }
    return false;
}

int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    cout << containsDuplicate(nums);
    return 0;
}