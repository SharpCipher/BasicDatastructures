/*
Given an array of integers nums and an integer target, return the indices of the two numbers
such that they add up to target.
*/
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& arr, int n, int target) {
    std::unordered_map<int, int> hashMap;
    for(int i=0; i<n; ++i) {
        int complement = target - arr[i];
        if(hashMap.find(complement) != hashMap.end()) {
            return {hashMap[complement], i};
        }
        hashMap[arr[i]] = i;
    }
    return {};
}

int main()
{
    int n, target;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    std::cout << "Entet the Elements: \n";
    std::vector<int> arr(n);
    for(int i=0; i<n; ++i) {
        std::cin >> arr[i];
    }
    std::cout << "Enter the target: ";
    std::cin >> target;
    std::vector<int> solutions = twoSum(arr, n, target);

    std::cout << "Indices: \n";
    for(int i=0; i<solutions.size(); ++i) {
        std::cout << solutions[i] << " ";
    }
    std::cout << '\n';

    return 0;
}