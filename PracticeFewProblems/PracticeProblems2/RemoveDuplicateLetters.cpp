/*Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"

Example 2:

Input: s = "cbacdcbc"
Output: "acdb"*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res="";
        int lastPosition[26];
        bool visit[26] = {false};
        
        for(int i=0; i<s.length(); i++)
            lastPosition[s[i]-'a'] = i;
        for(int i=0; i<s.length();i++){
            if(visit[s[i]-'a'])
                continue;
            while(!res.empty() && res.back()>s[i] && lastPosition[res.back()-'a']>i){
                char c = res.back();
                visit[c-'a'] = false;
                res.pop_back();
            }
            visit[s[i]-'a'] = true;
            res.push_back(s[i]);
        }
        
        return res;
    }
};
