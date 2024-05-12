#include <stdio.h>

size_t custom_strlen(const char* str) {
    if(str == NULL) {
        fprintf(stderr, "Error: Null pointer passed to custom_strlen\n");
        return 0;
    }
    size_t length = 0;
    while(*str != '\0') {
        length++;
        str++;
    }

    return length;
}

int main() {
    char *str = "Hello, world!";
    size_t length = custom_strlen(str);
    printf("Length of the string: %zu\n", length);

    char *null_str = NULL;
    size_t null_length = custom_strlen(null_str);
    printf("Length of null string: %zu\n", null_length);
    
    return 0;
}