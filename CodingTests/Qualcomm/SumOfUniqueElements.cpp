/*
Input : 1 2 2 3 3 4
Output: 1+4 = 5

Sum of elements which occurs only once.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

int sumOfUniqueElements(const std::vector<int>& elements) {
    std::unordered_map<int, int> frequencyCount;

    // Count the occurrence of each element
    for(int elem : elements) {
        frequencyCount[elem]++;
    }

    // Sum elements that occur only once
    int sum = 0;
    for(const auto& map : frequencyCount) {
        if(map.second == 1) {
            sum += map.first;
        }
    }

    return sum;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> elements(n);
    std::cout << "Enter " << n << " elements: ";
    for(int i=0; i<n; ++i) {
        std::cin >> elements[i];
    }

    int result = sumOfUniqueElements(elements);

    std::cout << "Sum of elements that occur only once: " << result << '\n';

    return 0;
}