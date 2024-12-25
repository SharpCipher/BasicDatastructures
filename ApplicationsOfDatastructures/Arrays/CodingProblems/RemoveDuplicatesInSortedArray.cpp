/*
Given a sorted array arr[] of size n, the goal is to rearrange the array so that all distinct elements appear at the beginning
in sorted order. Additionally, print the length of this distinct sorted subarray.
*/

#include <iostream>
#include <vector>

void removeDuplicates(std::vector<int>& arr) {
    int n = arr.size();
    if(n <= 1)
        return;
    
    int j = 1;
    for(int i=1; i<n; ++i) {
        if(arr[i] != arr[i-1]) {
            arr[j++] = arr[i];
        }
    }

    std::cout << "Array after removing duplicates: ";
    for(int i=0; i<j; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    std::cout << "New size of array: " << j << '\n';
}

int main()
{
    std::vector<int> arr;
    std::cout << "Enter 10 elements of array: ";
    for(int i=0; i<10; i++) {
        int k;
        std::cin >> k;
        arr.push_back(k);
    }

    removeDuplicates(arr);

    return 0;
}