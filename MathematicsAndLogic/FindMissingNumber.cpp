#include <iostream>
#include <vector>

int missingNumber(std::vector<int>& arr) {
    int n = arr.size() + 1;  // The size of the array should be n-1, so n is the total count
    std::cout << "N: " << n << '\n';
    int x1 = 0, x2 = 0;
    
    // XOR of all elements in the array
    for(int i = 0; i < arr.size(); ++i) {  // Loop over all elements of the array
        x1 ^= arr[i];
    }
    std::cout << "Xor1: " << x1 << '\n';
    
    // XOR of all numbers from 1 to n (inclusive)
    for(int i = 1; i <= n; ++i) {  // Loop over all numbers from 1 to n
        x2 ^= i;
    }
    std::cout << "Xor2: " << x2 << '\n';
    
    // The missing number is the XOR of the results from the two loops
    return x1 ^ x2;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 5};  // The missing number is 4
    int mNumber = missingNumber(arr);
    std::cout << "Missing Number: "<< mNumber << '\n';  // Should print 4
    
    return 0;
}

/*
N: 5
Xor1: 5
Xor2: 1
Missing Number: 4
*/
