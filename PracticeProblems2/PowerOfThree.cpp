/*
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

Example 1:

Input: n = 27
Output: true
Example 2:

Input: n = 0
Output: false
Example 3:

Input: n = 9
Output: true

@Leetcode Problem of the day
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0)
            return false;
        while(1){
            if(n == 1 || n == 3)
                return true;
            if(n%3 != 0)
                return false;
            n = n/3;
        }
        
        return true;
    }
};