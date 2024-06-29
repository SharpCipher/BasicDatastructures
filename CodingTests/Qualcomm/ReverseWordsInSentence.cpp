#include <iostream>

std::string reverseWords(std::string& str) {
    int n = str.length();
    int start = 0;
    for(int i=0; i<=n; ++i) {
        if(i == n || str[i] == ' ') {
            std::reverse(str.begin()+start, str.begin()+i);
            start = i+1;
        }
    }
    std::reverse(str.begin(), str.end());

    return str;
}

int main()
{
    std::string str;
    std::getline(std::cin, str);

    std::cout << reverseWords(str) << '\n';

    return 0;
}