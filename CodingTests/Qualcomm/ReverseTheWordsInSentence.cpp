/*
Input: Reverse the words in a sentence
Output: sentence a in words the Reverse
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

std::string reverseWords(const std::string& sentence) {
    std::istringstream iss(sentence);
    std::vector<std::string> words;
    std::string word;

    // Extract words from the sentence
    while(iss >> word) {
        words.push_back(word);
    }

    // Reverse the order of words
    std::reverse(words.begin(), words.end());

    // Construct the reversed sentence
    std::ostringstream oss;
    for(size_t i=0; i<words.size(); ++i) {
        oss << words[i];
        if(i != words.size()-1) {
            oss << " ";
        }
    }

    return oss.str();
}

int main()
{
    std::string sentence;

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    std::string reversedSentence = reverseWords(sentence);

    std::cout << "Reversed Sentence: " << reversedSentence << '\n';

    return 0;
}