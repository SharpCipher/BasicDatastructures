/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string ""


Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    int count;
    string res="";
    for(int i=0; i<strs[0].size(); i++){
        count=0;
        for(int j=1; j<strs.size(); j++){
            
            if(strs[j][i]==strs[0][i])
                count++;
            else
                return res;
        }
        res+=strs[0][i];
    }
    return res;
    }
};