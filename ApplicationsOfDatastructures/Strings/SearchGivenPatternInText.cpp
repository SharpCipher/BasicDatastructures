#include <iostream>
#include <string>

void searchPattern(char* pattern, char* text) {
    int m = strlen(pattern);
    int n = strlen(text);
    int flag = 0;

    // A loop to slide pattern[] one by one
    for(int i=0; i <= (n-m); ++i) {
        int j;

        // For current index i, check for pattern match
        for(j=0; j < m; ++j) {
            if(text[i+j] != pattern[j]) {
                break;
            }
        }

        // If pattern matches at index i
        if(j == m) {
            std::cout << "Pattern found at index: " << i << '\n';
            flag = 1; // At least one pattern found
        }
        else {
            // If not even one pattern found
            if(flag != 1) {
                flag = 2; // No pattern found
            }
        }
    }
    if(flag == 2) {
        std::cout << "Pattern not found in text.\n";
    }
}
int main()
{
    char txt1[] = "AABAACAADAABAABB";
    char pat1[] = "AABA";
    std::cout << "Example 1:\n";
    searchPattern(pat1, txt1);

    char txt2[] = "ABABDABACDABABCABAB";
    char pat2[] = "ABABCABAB";
    std::cout << "Example 2:\n";
    searchPattern(pat2, txt2);

    char txt3[] = "AAAAA";
    char pat3[] = "AAB";
    std::cout << "Example 3:\n";
    searchPattern(pat3, txt3);

    return 0;
}