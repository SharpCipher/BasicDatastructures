// Find K smallest elements in a given list of elements

#include <iostream>
#include <queue>
#include <vector>

std::vector<int> kSmallestElements(std::vector<int>& nums, int k) {
    // Min heap to keep track of the k smallest elements
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
    // Add elements to the heap
    for(int num : nums) {
        minHeap.push(num);
    }
    
    std::vector<int> result;
    for(int i = 0; i<k && !minHeap.empty(); ++i) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    
    return result;
}

int main() {
    
    // K sorted arrays
    std::vector<int> arr = {1, 5, 9, 12, 16, 23, 2, 8, 15};
    int k = 4;
    std::vector<int> res = kSmallestElements(arr, k);
    
    std::cout << k << " smallest elements are: ";
    for(int num : res) {
        std::cout << num << " ";
    }
    std::cout << '\n';
    
    return 0;
}


/*
Output:
4 smallest elements are: 1 2 5 8
*/
