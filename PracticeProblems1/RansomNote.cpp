/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

@Leetcode problem of the day
Difficulty level : Easy

*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char,int> umap;
        for(auto i : magazine){
            umap[i]++;
        }
        for(auto j : ransomNote){
            umap[j]--;
        }
        for(auto it : umap){
            if(it.second < 0){
                return false;
            }
        }
        return true;        
    }
};