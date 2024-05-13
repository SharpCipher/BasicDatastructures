#include <stdio.h>

void reverseString(char* str) {
    if(str == NULL) {
        printf("Null pointer passed!!\n");
        return;
    }

    // Find the length of the string
    size_t length = 0;
    while(str[length] != '\0') {
        length++;
    }

    // Reverse the string
    for(int i=0; i < length/2; ++i) {
        char temp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = temp;
    }
}

int main() {
    char str[] = "Hello, world!";
    printf("Original string: %s\n", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);
    return 0;
}