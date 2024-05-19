#include <iostream>
#include <string>

bool areAnagrams(std::string& str1, std::string& str2) {
    // Check if the lengths of the strings are not equal
    if(str1.length() != str2.length()) {
        return false;
    }

    // Sort both strings
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    return str1 == str2;
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