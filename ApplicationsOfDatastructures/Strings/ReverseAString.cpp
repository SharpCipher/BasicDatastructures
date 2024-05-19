#include <iostream>
#include <string>

void reverseStr(std::string& str){
    int n = str.length();
    for(int i=0, j=n-1; i<j; i++,j--){
        std::swap(str[i], str[j]);
    }
}

int main() {
    std::string str;
    getline(std::cin, str);
    reverseStr(str);
    std::cout<<str<<std::endl;
    return 0;
}