/*

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2

Example 2:

Input: nums = [3,1,3,4,2]
Output: 3


@LeetCode
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        int count = 0;
        while(l <= h){
            int m = l+(h-l)/2;
            count = 0;
            for(int i : nums){
                if(i <= m){
                    ++count;
                }
            }
            if(count <= m){
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
        return l;
    }
    
};