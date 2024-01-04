#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>

using namespace std;
vector<int> twoSum(const vector<int> &nums, int target)
{
    // APP 1
    // TC - O(NLogN)
    // SC - O(N)
    vector<int> res;
    int i = 0, j = nums.size();
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++)
    {
        umap.insert({nums[i], i});
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (umap.find(target - nums[i]) != umap.end() && i != umap[target - nums[i]])
        {
            return {i, umap[target - nums[i]]};
        }
    }
    return res;
}

int main()
{
    vector<int> A = {4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};
    int B = -3;
    twoSum(A, B);
    return 0;
}