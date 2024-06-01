#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to reverse any sequence starting with pointer
// begin, ending with pointer end
void reverse(char* begin, char* end) {
    char c;
    while(begin < end) {
        c = *begin;
        *begin++ = *end;
        *end-- = c;
    }
}

void reverseWords(char* s) {
    char* word_begin = NULL;

    // temp is for word boundary
    char* temp = s;

    // Step 1 : Reverse the individual words of of the string one by one
    // Ex: hcum yrev gnimmargorp ekil I
    while(*temp) {
        // Check that the string starts with the valid character(not space)
        if(word_begin == NULL && (*temp != ' ')) {
            word_begin = temp;
        }
        if(word_begin && ((*(temp+1) == ' ') || (*(temp+1) == '\0'))) {
            reverse(word_begin, temp);
            word_begin = NULL;
        }
        temp++;
    }

    // Step2 : Reverse the whole string generated after step1
    reverse(s, temp-1);
}

int main() {

    char s[] = "  I like programming very much";

    reverseWords(s);
    printf("%s\n", s);

    return 0;
}