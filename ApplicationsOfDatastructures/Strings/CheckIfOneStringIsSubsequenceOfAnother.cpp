#include <iostream>
#include <string>

bool isSubsequenceUtil(const std::string& s1, const std::string& s2, int m, int n) {
    // Base case
    if(m == 0) {
        return true;
    }

    if(n == 0) {
        return false;
    }

    // If last characters of two strings are matching
    if(s1[m-1] == s2[n-1]) {
        return isSubsequenceUtil(s1, s2, m-1, n-1);
    }

    // If last charcters of two strings are not matching
    else {
        return isSubsequenceUtil(s1, s2, m, n-1);
    }
}

bool isSubsequence(const std::string& s1, const std::string& s2) {
    int m = s1.length();
    int n = s2.length();

    if(m > n) {
        return false;
    }

    return isSubsequenceUtil(s1, s2, m, n);
}

int main()
{
    std::string s1;
    std::cout << "Enter a string1: ";
    std::getline(std::cin, s1);

    std::string s2;
    std::cout << "Enter a string2: ";
    std::getline(std::cin, s2);

    isSubsequence(s1, s2) ? std::cout << "Yes\n" : std::cout << "No\n";

    return 0;
}