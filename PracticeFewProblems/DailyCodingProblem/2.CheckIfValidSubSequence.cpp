#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


bool isValidSubsequence(vector<int> array, vector<int> sequence) {
    int n = sequence.size();
    int m = array.size();

    int i = 0;
    int j = 0;

    while(i < m && j < n) {
        if(array[i] == sequence[j]) {
            j++;
        }
        i++;
    }
    return (j == n);
}

int main() {
    // Test Case 1: Normal case, valid subsequence
    assert(isValidSubsequence({1, 2, 3, 4}, {1, 3, 4}) == true);

    // Test Case 2: Normal case, invalid subsequence
    assert(isValidSubsequence({1, 2, 3, 4}, {2, 4, 3}) == false);

    // Test Case 3: Edge case, empty sequence (should always be valid)
    assert(isValidSubsequence({1, 2, 3, 4}, {}) == true);

    // Test Case 4: Edge case, sequence equal to array
    assert(isValidSubsequence({1, 2, 3, 4}, {1, 2, 3, 4}) == true);

    // Test Case 5: Edge case, sequence larger than array (should be invalid)
    assert(isValidSubsequence({1, 2, 3, 4}, {1, 2, 3, 4, 5}) == false);

    // Test Case 6: Edge case, both array and sequence are empty
    assert(isValidSubsequence({}, {}) == true);

    // Test Case 7: Edge case, array is empty but sequence is not
    assert(isValidSubsequence({}, {1}) == false);

    // Test Case 8: Single element, valid
    assert(isValidSubsequence({5}, {5}) == true);

    // Test Case 9: Single element, invalid
    assert(isValidSubsequence({5}, {3}) == false);

    // Test Case 10: Sequence with repeated elements
    assert(isValidSubsequence({1, 2, 2, 3, 4}, {2, 2, 4}) == true);

    // Test Case 11: Array has duplicates, but sequence does not
    assert(isValidSubsequence({1, 1, 2, 3, 4}, {1, 2, 4}) == true);

    // Test Case 12: Sequence elements appear in array but in the wrong order
    assert(isValidSubsequence({1, 2, 3, 4, 5}, {1, 3, 2}) == false);

    // Test Case 13: Large input case
    vector<int> largeArray(1000000, 1);
    vector<int> largeSequence = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    assert(isValidSubsequence(largeArray, largeSequence) == true);

    // Test Case 14: Sequence longer than the array with matching elements
    assert(isValidSubsequence({1, 2, 3}, {1, 2, 3, 4}) == false);

    // Test Case 15: Random order in array, sequence should match
    assert(isValidSubsequence({5, 1, 22, 25, 6, -1, 8, 10}, {1, 6, -1, 10}) == true);

    cout << "All test cases passed!" << endl;

    return 0;
}
