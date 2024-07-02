#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
// https://leetcode.com/problems/container-with-most-water/

int maxArea(vector<int> &height)
{
    int max_area = 0;
    int p1 = 0, p2 = height.size() - 1;
    while (p1 < p2)
    {
        max_area = max(max_area, min(height[p1], height[p2]) * (p2 - p1));
        if (height[p1] < height[p2])
            p1++;
        else
            p2--;
    }
    return max_area;
}

int main()
{
    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(nums);
    return 0;
}