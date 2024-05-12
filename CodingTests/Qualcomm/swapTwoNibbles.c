#include <stdio.h>

void print_binary(unsigned char num) {
    printf("Binary representation: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

unsigned char swap_nibbles(unsigned char x) {
    return ((x & 0x0F) << 4) | ((x & 0xF0) >> 4);
}

int main() {
    unsigned char ch;

    // Input character
    printf("Enter a character: ");
    scanf("%c", &ch);

    // Print binary representation before swapping
    printf("Before swapping nibbles:\n");
    print_binary(ch);

    // Swap nibbles
    unsigned char swapped = swap_nibbles(ch);

    // Print binary representation after swapping
    printf("After swapping nibbles:\n");
    print_binary(swapped);

    printf("Result after swapping nibbles: %c\n", (unsigned char)swapped);

    return 0;
}
