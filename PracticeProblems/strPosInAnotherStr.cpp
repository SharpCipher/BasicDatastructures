#include <iostream>
#include <string>

// The function returns an integer indicating the startting location of the first occurrence
// of the second parameter string within the first parameter string.

int strPos(std::string s1, std::string s2){
    int len1, len2;
    int i, j1, j2;

    len1 = s1.length();
    len2 = s2.length();

    std::cout<<len1<<" "<<len2<<std::endl;

    for(i=0; i+len2 <= len1; i++){
        for(j1=i, j2=0; (j2 <= len2) && (s1[j1] == s2[j2]); j1++, j2++){}
        
        if(j2 == len2){
            return i;
        }
    }

    return -1;
}

int main(){
    std::string s1 = "Hello Mac World!";
    std::string s2 = "old";
    int pos = strPos(s1, s2);
    std::cout<<"pos: "<<pos<<std::endl;
    return 0;
}
