/*
Given a set of strings, find the longest common prefix.
Input  : {“geeksforgeeks”, “geeks”, “geek”, “geezer”}
Output : "gee"

Input  : {"apple", "ape", "april"}
Output : "ap"
*/

#include <iostream>
#include <string>
#include <vector>

void displayStrings(const std::vector<std::string>& input) {
    for(const auto& str : input) {
        std::cout << str << " ";
    }
    std::cout << '\n';
}

int findMinimumLengthString(const std::vector<std::string>& input) {
    int min = input[0].length();
    for(const auto& str : input) {
        if(str.length() < min) {
            min = str.length();
        }
    }

    return min;
}

std::string commonPrefix(const std::vector<std::string>& input) {
    int n = input.size();
    int minimumLen = findMinimumLengthString(input);

    std::string result = "";
    char currentChar;

    for(int i=0; i<minimumLen; ++i) {
        currentChar = input[0][i];
        for(int j=1; j<n; j++) {
            if(input[j][i] != currentChar)
                return result;
        }

        result.push_back(currentChar);
    }

    return result;
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