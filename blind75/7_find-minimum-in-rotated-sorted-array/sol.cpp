#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>

using namespace std;
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

int findMin(vector<int> &nums)
{
    // Binary search
    // TC - O(LogN)
    // SC - O(1)
    
    // only 1 element in the array.
    if(nums.size() == 1)
        return nums[0];

    if (nums[0] < nums[nums.size()-1]){
        // not rotated
        return nums[0];
    }

    int lo = 0, hi = nums.size()-1;
    while(lo < hi) {
        int mid = lo + (hi - lo)/2;
        if(nums[mid] > nums[mid + 1])
            return nums[mid+1];
        if(nums[mid - 1] > nums[mid])
            return nums[mid];
        
        if(nums[mid] > nums[lo])
            lo = mid+1;
        else
            hi = mid;
    }
    return nums[lo];
}

int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};
    findMin(nums);
    return 0;
}