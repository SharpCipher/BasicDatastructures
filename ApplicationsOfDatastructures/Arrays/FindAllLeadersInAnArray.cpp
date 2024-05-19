/*
Given an integer array X[] of size n, write a program to find all the leaders in the array X[].
An element is a leader if it is strictly greater than all the elements to its right side.

The last element of an array is a leader by default.
The largest element of an array is also a leader by default.
Suppose all the array elements are unique.
Ordering in the output doesn’t matter.

Example 1
Input: X[] = [16, 17, 4, 3, 5, 2], Output: [17, 5, 2]
Explanation: Element 2 is the rightmost element, so it is a leader by default. 17 and 5 are also leader
elements because they are greater than all the elements on their right side.

Example 2
Input: X[] = [6, 5, 4, 3, 2, 1], Output: [6, 5, 4, 3, 2, 1]
Explanation: All elements are leaders because they are greater than all the elements on their right side.
Element 1 is the rightmost element, so it is a leader by default.

Example 3
Input: X[] = [1, 2, 3, 4, 5, 6], Output: [6]
Explanation: Element 6 is the rightmost element, which is a leader by default. Otherwise, all elements are
less than all on their right side.
*/
#include <iostream>

void findAllLeaders(int input[], int n) {
    std::vector<int> leaders;
    int maxFromRight = input[n-1];
    leaders.push_back(maxFromRight); // last element is always a leader
    for(int i = (n-2); i >= 0; --i) {
        if(maxFromRight < input[i]) {
            maxFromRight = input[i];
            leaders.push_back(maxFromRight);
        }
    }
    std::cout << "Leaders in the given array: ";
    for(auto& x : leaders) {
        std::cout << x << " ";
    }
    std::cout << '\n';
}

int main() {
    int n;
    std::cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; ++i) {
        std::cin >> arr[i];
    }
    findAllLeaders(arr, n);
    return 0;
}