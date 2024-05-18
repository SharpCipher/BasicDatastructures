#include <iostream>

//subString(s1,i,j,s2) sets the string s2 to the j characters beginning at s1[i]
void subString(std::string s1, int i, int j, std::string s2){
    int k,m;
    for(k=i, m=0; m < j; s2[m++] = s1[k++])
        std::cout<<s2<<" ";
    std::cout<<std::endl;

    //s2[m] = '\0';

    std::cout<<"string s1: "<<s1<<std::endl;
    std::cout<<"string s2: "<<s2<<std::endl;
}
int main(){
    std::string s1 = "Bhanuprakash";
    std::string s2 = "abcdefghi";
    int i = 3;
    int j = 4;
    subString(s1, i, j, s2);

    return 0;
}