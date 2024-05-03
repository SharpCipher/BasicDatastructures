/*
Given a set of strings, find the longest common prefix.
Input  : {“geeksforgeeks”, “geeks”, “geek”, “geezer”}
Output : "gee"

Input  : {"apple", "ape", "april"}
Output : "ap"
*/

#include <iostream>
#include <vector>
#include <string>

void displayStrings(const std::vector<std::string>& input) {
    for(int i=0; i<input.size(); ++i) {
        std::cout << input[i] << " ";
    }
    std::cout << '\n';
}

std::string commonPrefixUtility(const std::string& str1, const std::string& str2) {
    std::string result = "";
    int length = std::min(str1.length(), str2.length());
    for(int i=0; i<length; ++i) {
        if(str1[i] != str2[i]) {
            break;
        }
        result += str1[i];
    }

    return result;
}

std::string commonPrefix(const std::vector<std::string>& input) {
    int n = input.size();
    std::string prefix = input[0];
    for(int i=1; i<n; ++i) {
        prefix = commonPrefixUtility(prefix, input[i]);
    }

    return prefix;
}

int main()
{
    std::vector<std::string> inputStrings;
    
    for(int i=0; i<5; ++i) {
        std::string str;
        std::cin >> str;
        inputStrings.push_back(str);
    }
    std::cout << "Entered strings: ";
    displayStrings(inputStrings);

    std::string longestPrefix = commonPrefix(inputStrings);

    std::cout << "Longest prefix: " << longestPrefix << '\n';

    return 0;
}