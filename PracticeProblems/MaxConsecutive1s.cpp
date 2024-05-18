/*

Given a binary array nums, return the maximum number of consecutive 1's in the array.

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Input: nums = [1,0,1,1,0,1]
Output: 2

@LeetCode Arrays

*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int c1 = 0;
        int maxOnes = 0;
        
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                c1++;
            }
            else if(nums[i] == 0){
                c1 = 0;
            }
            
            if(c1 > maxOnes){
                maxOnes = c1;
            }
        }
        return maxOnes;
    }
};