/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.*/

/*

Input: nums = [3,2,3]
output: 3

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> store;
        for(int i : nums){
            if(++store[i] > (nums.size())/2){
                return i;
            }
        }
        return 0;
    }
};