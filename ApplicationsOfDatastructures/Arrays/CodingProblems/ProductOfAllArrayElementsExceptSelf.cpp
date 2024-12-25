/*
Given an array X[] of n integers where n > 1, write a program to return an array product[] such that
product[i] is equal to the product of all the elements of X except X[i].

It's guaranteed that the product of the elements of any prefix or suffix of the array (including the
entire array) fits into a 32-bit integer. We need to solve this problem without using division operations.

Example 1
Input: X[] = [2, 1, 3, 4], Output: product[] = [12, 24, 8, 6]
Explanation:
Product except the 1st element = 1 * 3 * 4 = 12
Product except the 2nd element = 2 * 3 * 4 = 24
Product except the 3rd element = 2 * 1 * 4 = 8
Product except the 4th element = 2 * 1 * 3 = 6

Example 2
Input: X[] = [5, 2, 8, 4, 5], Output: product[] = [320, 800, 200, 400, 320]

Example 3
Input: X[] = [1, 0, 4, 3, 5], Output: product[] = [0, 60, 0, 0, 0]

Example 4
Input: X[] = [1, 1, 1, 1, 1, 1, 1], Output: product[] = [1, 1, 1, 1, 1, 1, 1]

Example 5
Input: X[] = [0, 4, 0, 3], Output: product[] = [0, 0, 0, 0]
*/

#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(int input[], const int n) {
    
    std::vector<int> prefixProduct(n);
    prefixProduct[0] = 1;
    for(int i=1; i<n; ++i) {
        prefixProduct[i] = input[i-1] * prefixProduct[i-1];
    }

    std::vector<int> suffixProduct(n);
    suffixProduct[n-1] = 1;
    for(int i=n-2; i>=0; --i) {
        suffixProduct[i] = input[i+1] * suffixProduct[i+1]; 
    }
    
    std::vector<int> product(n);
    for(int i=0; i<n; ++i) {
        product[i] = prefixProduct[i] * suffixProduct[i];
    }
    return product;
}

int main() {
    int n;
    std::cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; ++i) {
        std::cin >> arr[i];
    }
    std::vector<int> res;
    res = productExceptSelf(arr, n);
    for(int i=0; i<n; ++i) {
        std::cout << res[i] << " ";
    }
    std::cout << '\n';
}