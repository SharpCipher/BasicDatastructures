/*
Write a C program that, given an array A[] of n numbers and another number x,
determines whether or not there exist two elements in S whose sum is exactly x.
*/

#include <iostream>
#define MAX 100

void printPairs(int arr[], int n, int target) {
    int i, temp;
    bool binaryMap[MAX]={0}; // Initialize Hashmap to all zeros

    std::cout << "Pairs with given targetSum: \n";
    for(i=0; i<n; ++i) {
        temp = target - arr[i];
        if(temp >= 0 && binaryMap[temp] == 1) {
            std::cout << "{" << arr[i] << " " << temp << "}\t";
        }
        binaryMap[arr[i]] = 1; // Mark the array element as visited
    }
    std::cout << '\n';
}

int main() {

    int arr1[] = {1, 4, 45, 6, 2, 8};
    int arr2[] = {5, 3, 8, 1, 6, 2, 4, 0, 3};
    int x = 10;
    int y = 6;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printPairs(arr1, n1, x);
    printPairs(arr2, n2, y);

    return 0;
}