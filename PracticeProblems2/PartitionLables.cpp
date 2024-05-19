/*
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears 
in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

Example 2:

Input: s = "eccbbbbdec"
Output: [10]

@LeetCode
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26,0);
        vector<int> result;
        
        for(int i=0; i<s.length(); i++)
            freq[s[i] - 'a'] = i;
        int l=0,h=0;
        for(int i=0; i<s.length(); i++){
            h = max(h, freq[s[i]-'a']);
            
            if(i == h){
                result.push_back(i-l+1);
                l = i+1;
            }
        }
        
        return result;
    }
};