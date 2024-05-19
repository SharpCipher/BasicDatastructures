#include <iostream>
#include <string>

bool areAnagrams(const std::string& str1, const std::string& str2) {
    // Check if the lengths of the strings are not equal
    if(str1.length() != str2.length()) {
        return false;
    }

    // Create an array to store count of each character
    int charCount[256] = {0}; // Assuming ASCII characters

    // Count characters in str1
    for(char c : str1) {
        charCount[c]++;
    }

    // Subtract characters in str2
    for(char c : str2) {
        charCount[c]--;
    }

    // Check if all counts are zero
    for(int i=0; i<256; ++i) {
        if(charCount[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string str1, str2;
    std::cout << "Enter the first string: ";
    std::getline(std::cin, str1);

    std::cout << "Enter the second string: ";
    std::getline(std::cin, str2);

    if(areAnagrams(str1, str2)) {
        std::cout << "The strings are anagrams\n";
    }
    else {
        std::cout << "The strings are not anagrams\n";
    }
    return 0;
}