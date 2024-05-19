/*

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true

Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

Example 3:

Input: s = "abc"
Output: false

@LeetCode
*/

class Solution {
public:
    bool rest(string str, int i, int j){
        while(i < j){
            if(str[i] != str[j]){
                return false;
            }
            ++i;
            --j;
        }
        
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0;
        int h = s.size()-1;
        
        while(l < h){
            if(s[l] != s[h]){
                if(rest(s,l+1,h))
                    return true;
                else if(rest(s,l,h-1))
                    return true;
                else
                    return false;
                
            }
            ++l;
            --h;
        }
        
        return true;
    }
};