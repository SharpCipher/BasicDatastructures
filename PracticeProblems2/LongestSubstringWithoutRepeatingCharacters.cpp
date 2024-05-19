/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


@Leet Code
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0, j = 0;
        vector<int> temp(128);
        for(int i = 0; i < s.size(); ++i) {
            temp[s[i]] += 1;
            while(temp[s[i]] > 1) {
                --temp[s[j++]];
            }
            len = max(len, i - j + 1);
        }
        return len;
    }
};