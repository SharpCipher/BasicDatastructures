#include <stdio.h>
#include <string.h>

void printDuplicates(char* str) {
    int count[256] = {0}; // Assuming ASCII characters

    // Count occurrences of each character
    for(int i=0; i<strlen(str); i++) {
        count[str[i]]++;
    }

    // Print characters with count > 1
    printf("Duplicate characters in the string: ");
    for(int i=0; i<256; ++i) {
        if(count[i] > 1) {
            printf("%c ", i);
        }
    }
    printf("\n");

}

int main() {
    char str[] = "hello woorld!";
    printf("Original string: %s\n", str);
    printDuplicates(str);

    return 0;
}