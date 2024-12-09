/*
Problem: Given an array of integers and a target sum, find a contiguous subarray whose sum is equal to the target sum.
*/

#include <stdio.h>

int subarrayWithGivenSum(int arr[], int n, int target) {
    int start = 0, sum = 0;
    for(int end = 0; end < n; ++end) {
        sum += arr[end];
    
        while(sum > target && start <= end) {
            sum -= arr[start];
            start++;
        }
        
        if(sum == target) {
            printf("Subarray found between indices %d and %d\n", start, end);
            return 1;
        }
    }
    
    return 0;
}

int main() {
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n = 6;
    int target = 23;

    if (!subarrayWithGivenSum(arr, n, target)) {
        printf("No subarray found with the given sum.\n");
    }

    return 0;
}

/*
Subarray found between indices 2 and 3
*/
