/*
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order,
starting with word1. If a string is longer than the other, append the additional letters onto the end of the
merged string.
Return the merged string.
*/
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        string res = "";
        int i=0;
        int j=0;
        while(i < len1 && j < len2) {
            res += word1[i++];
            res += word2[j++];
        }
        while(i < len1) {
            res += word1[i++];
        }
        while(j < len2) {
            res += word2[j++];
        }

        return res;

    }
};