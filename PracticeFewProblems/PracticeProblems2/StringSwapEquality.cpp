/*

You are given two strings s1 and s2 of equal length. A string swap is an operation where you 
choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on 
exactly one of the strings. Otherwise, return false.

 

Example 1:

Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".

Example 2:

Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.

Example 3:

Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.

*/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2)
            return true;
        if(s1.size() != s2.size())
            return false;
        int freq[26] = {0};
        for(auto &i : s1)
            freq[i-'a']++;
        for(auto &i : s2)
            freq[i - 'a']--;
        for(auto &i : freq){
            if(i != 0){
                return false;
            }
        }
        int c = 0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i])
                c++;
            if(c > 2){
                return false;
            }
        }
        if(c == 2)
            return true;
        return false;
    }
};