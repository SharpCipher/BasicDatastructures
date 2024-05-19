/*
Given an array and a number k, remove all occurrences of k from the array (in-place). Return the number of elements 
'remainingSize' left after removing k. Note that removing the occurences is mandatory and will be checked in the main method.
There can be anything beyond the first 'remainingSize' elements. It will be ignored.

Array: [1, 4, 2, 6, 2, 6, 9, 4]
Number: 4
Answer: 6
Explanation:[1, 2, 6, 2, 6, 9]
*/
#include <iostream>
#include <vector>

int removeOccurences(std::vector<int> &A, int k) {
	// add your logic here
	int j = 0;
	for(int x : A) {
		if(x != k) {
			A[j] = x;
			j++;
		}
	}
	return j;
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
    int target;
    std::cout << "Enter the target: ";
    std::cin>>target;
    std::cout << "Number of elements after removal of all the occurences of " << target << ": ";
    std::cout << removeOccurences(arr, target) << '\n';
}