/*
The cumulative sum of an array at index i is defined as the sum of all elements of the array from index 0 to index i.
Examples
Initial Array: [1, 2, 3, 4]
Cumulative Sum: [1, 3, 6, 10]
Initial Array: [1, 1, 1, 1, 1]
Cumulative Sum: [1, 2, 3, 4, 5]
Initial Array: [1, 3, 5, 7, 9]
Cumulative Sum: [1, 4, 9, 16, 25]
Given an array, return its cumulative sum.
*/
#include <iostream>
#include <vector>

std::vector<int> getCumulativeSum(std::vector<int> &arr) {
	// add your logic here
	int n = arr.size();
	int sum = 0;
	for(int i=0; i<n; ++i) {
		sum += arr[i];
		arr[i] = sum;
	}
	return arr;
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    std::cout << "Enter " << n << " Elements: \n";
    std::vector<int> arr(n);
    for(int i=0; i<n; ++i) {
        std::cin>>arr[i];
    }
    std::vector<int> res = getCumulativeSum(arr);
    std::cout << "Cumulative sum array: ";
    for(int i=0; i<n; ++i) {
        std::cout << res[i] << " ";
    }
    std::cout << '\n';
    return 0;
}