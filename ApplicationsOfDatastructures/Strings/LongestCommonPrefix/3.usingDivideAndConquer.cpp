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
    int n1 = str1.length();
    int n2 = str2.length();

    for(int i=0, j=0; i<=n1-1 && j<=n2-1; i++, j++) {
        if(str1[i] != str2[j]) {
            break;
        }
        result.push_back(str1[i]);
    }

    return result;
}

std::string commonPrefix(const std::vector<std::string>& input, int low, int high) {
    if(low == high){
        return input[low];
    }
        int mid = low + (high - low)/2;
        std::string str1 = commonPrefix(input, low, mid);
        std::string str2 = commonPrefix(input, mid+1, high);

        return commonPrefixUtility(str1, str2);
}

int main()
{
    std::vector<std::string> inputStrings;
    
    for(int i=0; i<5; ++i) {
        std::string str;
        std::cin >> str;
        inputStrings.push_back(str);
    }
    int len = inputStrings.size();
    std::cout << "Entered strings: ";
    displayStrings(inputStrings);

    std::string longestPrefix = commonPrefix(inputStrings, 0, len-1);
    std::cout << "Longest prefix: " << longestPrefix << '\n';

    return 0;
}