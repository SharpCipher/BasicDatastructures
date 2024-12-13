// Reverse the order of words in a sentence

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverse(char* str, int start, int end) {
    while(start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        
        start++;
        end--;
    }
}

// Function to reverse words in a sentence
void reverseWords(char* str) {
    int len = strlen(str);
    
    // Step1 : Reverse the entire string
    reverse(str, 0, len-1);
    
    // Step2 : Reverse each words
    int wordStart = -1;
    for(int i=0; i<=len; ++i) {
        if(isspace(str[i]) || str[i] == '\0') {
            if(wordStart != -1) {
                reverse(str, wordStart, i-1);
                wordStart = -1;
            }
        }
        else if(wordStart == -1) {
            wordStart = i;
        }
    }
}

int main() {
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;
    
    reverseWords(str);
    
    printf("Reversed sentence: %s\n", str);
    
    return 0;
}

/*
Notes:-

The C program reverses the words in a sentence by following these steps:

1. **Reversing the Entire String**:
   - The `reverse` function takes a substring and reverses its characters.
   - In the `reverseWords` function, the first operation is to reverse the entire sentence. This is done by calling `reverse(str, 0, len - 1)`, where `len` is the length of the string. After this step, the sentence will be reversed in character order, but the words will still be in reverse order.

2. **Reversing Each Word**:
   - After reversing the whole sentence, the program proceeds to reverse each word back to its original form. It does this by iterating through each character of the reversed string:
     - It identifies the start of each word by checking for non-space characters.
     - It tracks the beginning of each word with `wordStart`.
     - When a space or the end of the string is encountered, it calls the `reverse` function to reverse the word between `wordStart` and the current position (`i - 1`).
   
   This ensures that each word gets reversed back into its original form, but the words themselves are in the correct order.

3. **Input and Output**:
   - The user is prompted to enter a sentence, which is stored in the `str` array.
   - The `fgets` function is used to read the input string, and `strcspn` is used to remove any trailing newline character (`\n`) from the input.
   - The `reverseWords` function is called to process the string, and the final reversed sentence is printed.

### Example Breakdown:

For the input sentence:  
```
Hello world from C
```

1. **Reverse the Entire String**:  
   First, the entire sentence is reversed:  
   ```
   C from world Hello
   ```

2. **Reverse Each Word**:  
   Then each word is reversed back to its original form:  
   ```
   C from world Hello
   ```

### Key Functions:

- **`reverse(char *str, int start, int end)`**: Reverses a substring of `str` from index `start` to `end`.
- **`reverseWords(char *str)`**: Reverses the entire string and then reverses each word individually to maintain the correct word order.
*/
