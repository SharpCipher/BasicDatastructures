#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strSize) {
    if(strSize == 0)
        return "";

    // Starts with the first string as the current longest prefix
    char* prefix = strdup(strs[0]);

    for(int i=1; i<strSize; ++i) {
        int j=0;

        // Compare each character of the current longest prefix with
        // the corresponding character of the next string
        while(prefix[j] && strs[i][j] && prefix[j] == strs[i][j]) {
            j++;
        }

        // Update the current longest prefix
        prefix[j] = '\0';
    }

    return prefix;
}

int main() {
    char* arr[] = {"flower", "floor", "flour"};
    int n = sizeof(arr) / sizeof(arr[0]);

    char* res = longestCommonPrefix(arr, n);

    printf("Longest common prefix : %s\n", res);

    free(res);

    return 0;
}