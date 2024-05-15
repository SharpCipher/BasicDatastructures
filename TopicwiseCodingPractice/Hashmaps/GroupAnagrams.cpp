#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strings) {
    std::unordered_map<std::string, std::vector<std::string>> hashMap;
    for(const auto& str : strings) {
        std::string sortedStr = str;
        std::sort(sortedStr.begin(), sortedStr.end());
        hashMap[sortedStr].push_back(str);
    }
    std::vector<std::vector<std::string>> result;
    for(const auto& pair : hashMap) {
        result.push_back(pair.second);
    }

    return result;
}

int main()
{
    std::vector<std::string> input;
    std::cout << "Enter the strings...\nEnter -1 to exit input console\n";
    std::string s;
    while(std::getline(std::cin, s) && s != "-1") {
        input.push_back(s);
    }
    std::vector<std::vector<std::string>> res = groupAnagrams(input);
    
    for(const auto& group : res) {
        for(const auto& str : group) {
            std::cout << str << " ";
        }
        std::cout << '\n';
    }

    return 0;
}