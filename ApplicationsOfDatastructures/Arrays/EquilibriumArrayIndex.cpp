/*
Write a program to find the equilibrium index of an array. The equilibrium index of an array is 
an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes.

In other words, the equilibrium index of an array is an index 'i' such that the sum of elements at
indices less than 'i' is equal to the sum of elements at indices greater than 'i'.
A[0] + A[1] + ... + A[i - 1] = A[i + 1] + ... + A[n - 1], where 0 <= i <= n - 1.

For i = 0, we assume that the sum of elements at lower indexes is equal to 0.
For i = n - 1, we assume that the sum of elements at higher indexes is equal to 0.

Example 1:
Input: A[] = [-7, 1, 5, 2, -4, 3, 0], Output: 3
Explanation: 3 is an equilibrium index, i.e., A[0] + A[1] + A[2] = A[4] + A[5] + A[6] = -1.

Example 2:
Input: A[] = [0, 1, 3, -2, -1], Output: 1
Explanation: 1 is an equilibrium index, i.e., A[0] = A[2] + A[3] + A[4] = 0.

Example 3:
Input: A[] = [1, 2, -2, -1], Output: -1
Explanation: There is no such equilibrium index in the array.

Follow-up questions:

 For calculating the equilibrium index, do we need to include index i in the left or right part?
 No, the element at index i is not included in either part.
 Is there a possibility of multiple equilibrium indexes? 
 No, it is stated that there is atmost only one equilibrium index in the array. 
 Return the index if it is present; otherwise, return -1.
 Are the input values only positive? 
 No, they may be positive, negative, or zero.
 Are the input values unique?
 No, they can be repeated.
*/
#include <iostream>
int equilibriumIndexArray(int arr[], const int n) {
    int totalSum = 0;
    int leftSum = 0;

    for(int i=0; i<n; ++i) {
        totalSum += arr[i];
    }
    for(int i=0; i<n; ++i) {
        int rightSum = totalSum - leftSum - arr[i];
        if(leftSum == rightSum) {
            return i;
        }
        leftSum += arr[i];
    }

    return -1;
}

int main() {
    int n;
    std::cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; ++i) {
        std::cin >> arr[i];
    }
    int res = equilibriumIndexArray(arr, n);
    if(res >= 0)
        std::cout << "Equilibrium index is: " << res << std::endl;
    else
        std::cout << "Equilibrium index not found\n";
}