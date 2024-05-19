#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/*
Given two strings needle and haystack, return the index
of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        // if needle doesn't exist in haystack
        if(haystack.find(needle) == string::npos)
            return -1;
        int l1 = haystack.size();
        int l2 = needle.size();

        for(int i=0; i<l1-l2+1; ++i){
            // if any substring in haystack with size l2 == needle
            if(needle == haystack.substr(i,l2))
                return i;
        }
        return -1;
    }
};

int main() {

    string haystack, needle;
    int res;
    getline(cin, haystack);
    getline(cin, needle);

    Solution s;
    res = s.strStr(haystack, needle);
    cout<<res<<endl;

    return 0;
}