/*
Problem: Given an array of integers where each element is between 1 and n-1, find the duplicate element. 
Assume there is only one duplicate.

Approach: Floyd’s Tortoise and Hare (Cycle Detection)
The key idea is that since all numbers are between 1 and n−1, they can be treated as pointers to other array positions. The problem can be reduced to finding a cycle in this "linked list".

Tortoise and Hare Method:

The "tortoise" moves one step at a time.
The "hare" moves two steps at a time.
If there is a cycle, the tortoise and hare will eventually meet inside the cycle. Once they meet, we can detect the duplicate using another phase of the algorithm.
Phase 1: Detect the cycle.

Initialize the tortoise and hare at the beginning of the array.
Move the tortoise one step and the hare two steps until they meet (indicating a cycle).
Phase 2: Find the entry point of the cycle (i.e., the duplicate number).

After detecting the cycle, place one pointer at the start of the array and leave the other pointer at the meeting point.
Move both pointers one step at a time. The point where they meet will be the duplicate.
*/

#include <stdio.h>

// Function to find the duplicate using Floyd's Tortoise and Hare algorithm
int findDuplicate(int arr[], int n) {
    int tortoise = arr[0];
    int hare = arr[0];

    // Phase 1: Detect cycle
    do {
        tortoise = arr[tortoise];  // Move tortoise by 1 step
        hare = arr[arr[hare]];     // Move hare by 2 steps
    } while (tortoise != hare);

    // Phase 2: Find the entry point of the cycle (duplicate)
    tortoise = arr[0];  // Start tortoise from the beginning
    while (tortoise != hare) {
        tortoise = arr[tortoise];  // Move tortoise by 1 step
        hare = arr[hare];          // Move hare by 1 step
    }

    return tortoise;  // Return the duplicate number
}

int main() {
    int arr[] = {3, 1, 3, 4, 2};  // Example array with duplicate
    int n = 5;  // Size of the array
    int duplicate = findDuplicate(arr, n);
    printf("Duplicate is: %d\n", duplicate);
    return 0;
}

/*
Duplicate is: 3
*/
