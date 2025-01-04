/*
Problem statement:
Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings
(i.e. left substring and right substring).
The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

Example 1:

Input: s = "011101"
Output: 5 
Explanation: 
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5 
left = "01" and right = "1101", score = 1 + 3 = 4 
left = "011" and right = "101", score = 1 + 2 = 3 
left = "0111" and right = "01", score = 1 + 1 = 2 
left = "01110" and right = "1", score = 2 + 1 = 3
Example 2:

Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
Example 3:

Input: s = "1111"
Output: 3
*/
#include <iostream>
#include <string>
#include <climits>

class Solution {
public:
    int maxScore(std::string s) {
        int n = s.size();
        int c1 = 0;
        int c2 = 0;
        int res = INT_MIN;
        // Count the number of 1's in the string
        for(int i=0; i<n; ++i) {
            if(s[i] == '1') {
                c1++;
            }
        }
        // We are not considering the last character as it will be in the right substring
        for(int i=0; i<n-1; ++i) {
            if(s[i] == '0') { // If the character is 0, increment the count of 0's in the left substring
                c2++;
            }
            else {  // If the character is 1, decrement the count of 1's in the right substring
                c1--;
            }
            // split the string at i and calculate the score
            // For example, if i=0, left = "0" and right = "11101", score = 1 + 4 = 5
            // If i=1, left = "01" and right = "1101", score = 1 + 3 = 4
            // If i=2, left = "011" and right = "101", score = 1 + 2 = 3
            // If i=3, left = "0111" and right = "01", score = 1 + 1 = 2
            // If i=4, left = "01110" and right = "1", score = 2 + 1 = 3
            res = std::max(res, c1+c2); // Update the result with the maximum score
        }

        return res;
    }
};

int main() {

    Solution s;
    std::string str1 = "011101";
    std::cout << "Maximum score after splitting the string1: " << s.maxScore(str1) << '\n';

    std::string str2 = "00111";
    std::cout << "Maximum score after splitting the string2: " << s.maxScore(str2) << '\n';

    std::string str3 = "1111";
    std::cout << "Maximum score after splitting the string3: " << s.maxScore(str3) << '\n';

    std::string str4 = "00000";
    std::cout << "Maximum score after splitting the string4: " << s.maxScore(str4) << '\n';

    std::string str5 = "11111";
    std::cout << "Maximum score after splitting the string5: " << s.maxScore(str5) << '\n';

    std::string str6 = "010101010101";
    std::cout << "Maximum score after splitting the string6: " << s.maxScore(str6) << '\n';

    return 0;
}

/*
Output:
Maximum score after splitting the string1: 5
Maximum score after splitting the string2: 5
Maximum score after splitting the string3: 3
Maximum score after splitting the string4: 4
Maximum score after splitting the string5: 4
Maximum score after splitting the string6: 7
*/