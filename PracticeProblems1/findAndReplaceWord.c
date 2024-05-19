#include <stdio.h>
#include <string.h>

void replaceWord(char *sentence, const char *oldWord, const char *newWord) {
    char *foundWord = strstr(sentence, oldWord);

    // If the old word is not found, return
    if(foundWord == NULL) {
        return;
    }

    int oldWordLength = strlen(oldWord);
    int newWordLength = strlen(newWord);
    int sentenceLength = strlen(sentence);

    // If the new word is longer or shorter than the old word, shift the rest of the sentence accordingly
    memmove(foundWord + newWordLength, foundWord + oldWordLength, sentenceLength - (foundWord - sentence) - oldWordLength);

    // Copy the new word into the sentence
    strncpy(foundWord, newWord, newWordLength);
}

int main() {
    char sentence[100], oldWord[20], newWord[20];

    printf("Enter the sentece: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; // Remove the newline character

    printf("Enter the word to replace: ");
    scanf("%s", oldWord);
    printf("Enter the new word: ");
    scanf("%s", newWord);

    replaceWord(sentence, oldWord, newWord);

    printf("Modified sentence: %s\n", sentence);

    return 0;
}