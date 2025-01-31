/*
Given an array of integers, return a new array such that each element at index i of the new array is
the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. 
If our input was [3, 2, 1], the expected output would be [2, 3, 6].
*/

#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n, 1);

    // Step1 : Calculate left product for each element
    int left_product = 1;
    for(int i=0; i<n; ++i) {
        result[i] = left_product;
        left_product *= nums[i];
    }

    // Step2 : Calculate the right product and multiply with the left product stored in result
    int right_product = 1;
    for(int i=n-1; i>=0; --i) {
        result[i] *= right_product;
        right_product *= nums[i];
    }

    return result;
}


int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for(int i=0; i<n; ++i) {
        std::cin >> arr[i];
    }

    std::vector<int> res = productExceptSelf(arr);

    for(int val : res)
        std::cout << val << " ";

    std::cout << '\n';
    

    return 0;
}

/*
Notes:
we can use two passes through the array to avoid division and achieve an efficient solution.
The idea is to create two additional arrays (or use two temporary variables) to store the product of all elements to
the left and the right of each index, then multiply these together for the final result.

Left Product Array: Create an array where each element at index i contains the product of all elements to the left of i in
the original array.
Right Product Array: Similarly, create another array where each element at index i contains the product of all elements to
the right of i in the original array.
Result Array: The result at each index i is the product of the corresponding elements from the Left Product Array and 
the Right Product Array.
*/