#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>

using namespace std;
// https://leetcode.com/problems/search-in-rotated-sorted-array/

int search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 1) {
        if(nums[0] != target)
            return -1;
        else   
            return 0;
    }

    int lo = 0, hi = n - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(nums[mid] == target)
            return mid;
        if(nums[lo] <= nums[mid]){
            // [lo..mid] is sorted
            if(target >= nums[lo] && target < nums[mid])
                hi = mid-1;
            else 
                lo = mid+1;
        }
        else{
            if(target > nums[mid] && target <= nums[hi])
                lo = mid+1;
            else
                hi = mid-1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    search(nums, target);
    return 0;
}