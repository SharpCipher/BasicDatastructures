/*
Example:
input : abdc
Unique Substrings:
a, b, ab, abd, abdc, b, bd, bdc, d, dc, c

*/

#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::string s;
    std::cin >> s;
    std::vector<std::string> vec;
    for(int i=0; i<s.length(); i++) {
        vec.push_back(s.substr(i, s.length()-i));
    }
    sort(vec.begin(), vec.end(), std::greater<std::string>());

    std::cout << vec[0] << '\n';
    return 0;
}
