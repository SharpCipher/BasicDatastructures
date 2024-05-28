#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readInputString() {
    char* str = NULL;
    char c;
    int i = 0;
    
    str = (char*)malloc(sizeof(char));
    if(!str) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    while((c = getc(stdin)) != '\n' && (c != EOF)) {
        str[i] = c;
        i++;

        char* temp = (char*)realloc(str, (i+1)*sizeof(char));
        if(!temp) {
            free(str);
            fprintf(stderr, "Unable to reallocate memory\n");
            exit(1);
        }
        str = temp;
    }
    str[i] = '\0';

    return str;
}

void reverseString(char* str) {
    char* start = str;
    char* end = str + strlen(str) - 1;
    char c;

    while(end > start) {
        c = *start;
        *start = *end;
        *end = c;

        start++;
        end--;
    }
}

int main() {
    printf("Enter the string: \n");
    char* input = readInputString();
    reverseString(input);
    printf("Reversed string: %s\n", input);

    return 0;
}