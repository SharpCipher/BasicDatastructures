/*

Given an array nums of integers, return how many of them contain an even number of digits.

Examples:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.

@LeetCode

*/

class Solution {
public:
    
    int countDigits(int n){
        int c = 0;
        
        while(n > 0){
            n = n/10;
            c = c+1;
        }
        return c;
    }
    
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int res;
        
        for(int i=0; i<n; i++){
            
            res = countDigits(nums[i]);
            if(res%2 == 0){
                count++;
            }
        }
        return count;
    }
};