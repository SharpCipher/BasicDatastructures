/*
An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

    For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.

Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

Example 1:

Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.

Example 2:

Input: nums = [1]
Output: 0

@LeetCode
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return 0;
        }
        int index = 0;
        int c = 0;
        int d;
        int d0 = nums[1]-nums[0];
        for(int i=1; i<n-1; i++){
            d = nums[i+1] - nums[i];
            if(d == d0){
                ++index;
            }
            else{
                d0 = d;
                index = 0;
            }
            c = c+index;
        }
        return c;
    }
};