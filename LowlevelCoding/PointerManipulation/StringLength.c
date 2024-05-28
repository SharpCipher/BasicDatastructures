#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readInputString() {
    char* str = NULL;
    char c;
    int i = 0;

    str = (char*)malloc(sizeof(char)); // Allocate initial space for one character
    if(!str) {
        // Handle memory allocation failure
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    while((c = getc(stdin)) != '\n' && (c != EOF)) {
        str[i] = c;
        i++;
        
        // Reallocate memory for the new character plus null terminator
        char* temp = (char*)realloc(str, (i+1)*sizeof(char));

        if(!temp) {
            // Handle memory reallocation failure
            free(str);
            fprintf(stderr, "Unable to reallocate memory\n");
            exit(1);
        }
        str = temp;
    }
    str[i] = '\0';

    return str;
}

int main() {
    char *input;
    printf("Enter the string: \n");
    char *str = readInputString();
    int leng = 0;
    while(*str != '\0') {
        leng++;
        str++;
    }
    printf("Length of the string %s is: %d\n", str, leng);

    return 0;
}