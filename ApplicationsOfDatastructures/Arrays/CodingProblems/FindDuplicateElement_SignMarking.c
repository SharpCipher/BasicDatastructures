/*
Problem: Given an array of integers where each element is between 1 and n-1, find the duplicate element. 
Assume there is only one duplicate.
*/

#include <stdio.h>
#include <stdlib.h>
int findDuplicates(int arr[], int n) {
    for(int i=0; i<n; ++i) {
        int absVal = abs(arr[i]);
        
        if(arr[absVal - 1] < 0) {
            return absVal;
        }
        
        arr[absVal - 1] = -arr[absVal - 1];
    }
    
    return -1;
}

int main() {
    int arr[] = {1, -4, 3, 3, 4, 7, 0};  // Test case with negative numbers
    int n = 7;
    printf("Duplicate is: %d\n", findDuplicates(arr, n));
    return 0;
}

/*
Duplicate is: 3
*/
