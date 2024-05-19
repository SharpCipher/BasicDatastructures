/*
Given an array of n elements that contains elements from 0 to n-1, with any of these numbers
appearing any number of times.

Input: n=7 , array[]={1, 2, 3, 6, 3, 6, 1}
Output: 1, 3, 6
*/

#include <iostream>
#include <vector>
#include <map>

std::vector<int> findDuplicates(const std::vector<int>& arr, int n) {
    std::unordered_map<int, int> frequencyMap;
    std::vector<int> res;

    for(int i=0; i<n; ++i) {
        frequencyMap[arr[i]]++;
    }

    for(auto& entry : frequencyMap) {
        if(entry.second > 1) {
            res.push_back(entry.first);
        }
    }

    if(res.empty()) {
        res.push_back(-1);
    }

    sort(res.begin(), res.end());

    return res;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i=0; i<n; ++i) {
        std::cin >> arr[i];
    }

    std::vector<int> duplicates = findDuplicates(arr, n);

    std::cout << "Duplicates found: \n";
    for(int elem : duplicates) {
        std::cout << elem << " ";
    }
    std::cout << '\n';

    return 0;
}