/*
Problem: Given an array of integers, find the maximum product of two elements.

Approach: Traverse the array and track the two largest and two smallest numbers, since the product of two negative numbers could also be large.
*/

#include <stdio.h>

int maxProduct(int arr[], int n) {
    // Handle edge case where there are less than 2 elements
    if (n < 2) {
        return 0;  // No product can be formed
    }

    // Initialize the first two largest and two smallest values
    int max1 = arr[0], max2 = arr[1];
    int min1 = arr[0], min2 = arr[1];

    // Ensure max1 and max2 are in order
    if (max1 < max2) {
        max1 = arr[1];
        max2 = arr[0];
    }
    // Ensure min1 and min2 are in order
    if (min1 > min2) {
        min1 = arr[1];
        min2 = arr[0];
    }

    // Traverse the array to find the two largest and two smallest values
    for (int i = 2; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2) {
            max2 = arr[i];
        }

        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2) {
            min2 = arr[i];
        }
    }

    // Return the maximum of the two potential maximum products
    int product1 = max1 * max2;  // Product of two largest numbers
    int product2 = min1 * min2;  // Product of two smallest numbers

    return (product1 > product2) ? product1 : product2;
}

int main() {
    int arr[] = {1, -4, 3, -6, 7, 0}; 
    int n = 6;
    printf("Maximum product is: %d\n", maxProduct(arr, n));
    return 0;
}

/*
Maximum product is: 24
*/
