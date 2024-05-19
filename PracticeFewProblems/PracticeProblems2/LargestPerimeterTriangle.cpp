/*

Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, 
formed from three of these lengths.
If it is impossible to form any triangle of a non-zero area, return 0.

Example 1:

Input: nums = [2,1,2]
Output: 5

Example 2:

Input: nums = [1,2,1]
Output: 0

@LeetCode
*/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=n-1; i>1; i--){
            if((nums[i-1]+nums[i-2]) > nums[i]){
                return nums[i-1]+nums[i-2]+nums[i];
            }
        }
        return 0;
    }
};