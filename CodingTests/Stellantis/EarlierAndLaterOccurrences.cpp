/*
Given an array of integers, for each element determine whether that element occurs earlier in the array and whether it occurs later
in the array. Create two strings of binary digits. In the first string, each character is a 1 if the value at that
index also occurs earlier in the array, or 0 if not. In the second string, each character is a 1 if the value at that index occurs
later in the array, or 0 if not. Return an array of two strings where the first string is related to lower indices and the second string
to higher.

Example:
arr = [1, 2, 3, 2, 1]

output:
['00011', '11000']

1 => there is no early occurrence but occured later so:
str1 = 0
str2 = 1

same for 2:
Now, str1 = 00
str2 = 11

Next 3:
It has only one occurrence:
str1 = 000
str2 = 110

Next 2:
It has occurred earlier but not later(with respect to current index)
str1 = 0001
str2 = 1100

Next 3:
same:
str1 = 00011
str2 = 11000

1 <= n <= 10^4
0 <= arr <= 10^4
*/

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<std::string> findEarlierAndLaterOccurrences(const std::vector<int>& arr) {
    int n = arr.size();

    // Resultant strings for earlier and later occurrences
    std::string s1(n, '0'); // This will track earlier occurrences
    std::string s2(n, '0'); // This will track later occurrences

    // Map to track occurrences during traversal
    std::unordered_map<int, int> counter;

    // First Pass : traverse from left to right to fill s1
    for(int i = 0; i < n; ++i) {
        // Check if the current element has appeared before
        if(counter[arr[i]] > 0) {
            s1[i] = '1';
        }

        // Record current element's occurrence
        counter[arr[i]]++;
    }

    // Second Pass : traverse from right to left to fill s2
    counter.clear();

    for(int i = n-1; i >= 0; --i) {
        // Check if the current element has appeared after
        if(counter[arr[i]] > 0) {
            s2[i] = '1';
        }

        // Record current element's occurrence
        counter[arr[i]]++;
    }

    return {s1, s2};

}

int main() {
    // Case 1: Distinct elements
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::cout << "Case 1: Distinct elements" << std::endl;
    auto res1 = findEarlierAndLaterOccurrences(arr1);
    std::cout << "Earlier Occurrences: " << res1[0] << std::endl;
    std::cout << "Later Occurrences: " << res1[1] << std::endl;

    // Case 2: Some repeated elements
    std::vector<int> arr2 = {1, 2, 2, 3, 4, 4, 5};
    std::cout << "Case 2: Some repeated elements" << std::endl;
    auto res2 = findEarlierAndLaterOccurrences(arr2);
    std::cout << "Earlier Occurrences: " << res2[0] << std::endl;
    std::cout << "Later Occurrences: " << res2[1] << std::endl;


    // Case 3: All elements the same
    std::vector<int> arr3 = {1, 1, 1, 1, 1};
    std::cout << "Case 3: All elements the same" << std::endl;
    auto res3 = findEarlierAndLaterOccurrences(arr3);
    std::cout << "Earlier Occurrences: " << res3[0] << std::endl;
    std::cout << "Later Occurrences: " << res3[1] << std::endl;


    // Case 4: No elements (empty vector)
    std::vector<int> arr4 = {};
    std::cout << "Case 4: No elements (empty vector)" << std::endl;
    auto res4 = findEarlierAndLaterOccurrences(arr4);
    std::cout << "Earlier Occurrences: " << res4[0] << std::endl;
    std::cout << "Later Occurrences: " << res4[1] << std::endl;

    // Case 5: Elements in descending order
    std::vector<int> arr5 = {5, 4, 3, 2, 1};
    std::cout << "Case 5: Elements in descending order" << std::endl;
    auto res5 = findEarlierAndLaterOccurrences(arr5);
    std::cout << "Earlier Occurrences: " << res5[0] << std::endl;
    std::cout << "Later Occurrences: " << res5[1] << std::endl;

    return 0;
}