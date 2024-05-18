/*

Given an array nums of n integers where nums[i] is in the range [1, n], 
return an array of all the integers in the range [1, n] that do not appear in nums.

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:

Input: nums = [1,1]
Output: [2]

@LeetCode

 
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> dissapearedNumbers;
        int ptr1 = nums[0], ptr2;
        
        for(int i=0; i<nums.size(); ++i){
            ptr2 = nums[i];
            while(ptr2>-1){
                ptr1 = nums[ptr2-1];
                nums[ptr2-1] = -1;
                ptr2 = ptr1;
            }
        }
        for(int i=0; i<nums.size(); ++i)
            if(nums[i]!=-1)
                dissapearedNumbers.push_back(i+1);
        return dissapearedNumbers;
    }
};