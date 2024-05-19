/*
Given an array of n elements that contains elements from 0 to n-1, with any of these numbers
appearing any number of times.

Find these repeating numbers in O(n) and use only constant memory space.

Input: n=7 , array[]={1, 2, 3, 6, 3, 6, 1}
Output: 1, 3, 6
*/

#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> findDuplicates(std::vector<int>& arr, int n) {
    std::vector<int> res;

    for(int i=0; i<n; ++i) {
        int index = abs(arr[i]);
        if(arr[index] >= 0) {
            arr[index] = -arr[index];
        }
        else {
            res.push_back(index);
        }
    }

    return res;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i=0; i<n; ++i) {
        std::cin >> arr[i];
    }

    std::vector<int> duplicates = findDuplicates(arr, n);

    std::cout << "Duplicates found: \n";
    for(int elem : duplicates) {
        std::cout << elem << " ";
    }
    std::cout << '\n';

    return 0;
}

