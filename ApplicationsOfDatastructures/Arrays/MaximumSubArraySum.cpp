/*
Given an array of n numbers, our task is to calculate the maximum subarray
sum, i.e., the largest possible sum of a sequence of consecutive values in the
array. The problem is interesting when there may be negative values in the array
*/

#include <iostream>

int main() {

    int n;
    std::cin>>n;
    int* arr = new int[n];
    for(int i=0; i<n; ++i) {
        std::cin>>arr[i];
    }
    int best = INT_MIN;
    int sum = 0;

    for(int k=0; k<n; ++k) {
        sum = std::max(arr[k], sum+arr[k]);
        best = std::max(best, sum);
    }

    std::cout << best << '\n';

    return 0;
}