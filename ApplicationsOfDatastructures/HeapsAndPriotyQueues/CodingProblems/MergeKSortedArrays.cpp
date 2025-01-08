#include <iostream>
#include <queue>
#include <vector>

// A structure to represent an element, the specific array (array index), and the index in the selected array
struct Element {
    int value;
    int arrIndex;
    int indexInArr;
    
    Element(int v, int ai, int iai) : value(v), arrIndex(ai), indexInArr(iai) {}
    
    // Define a comparision operator to make the min-heap work (Smaller values have higher priority)
    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

std::vector<int> mergeKSortedArrays(const std::vector<std::vector<int>>& arrays) {
    // Min heap to store the elements
    std::priority_queue<Element, std::vector<Element>, std::greater<Element>> minHeap;
    
    // Step1 : Insert the first element of each array into the heap
    for(int i=0; i < arrays.size(); ++i) {
        if(!arrays[i].empty()) {
            minHeap.push(Element(arrays[i][0], i, 0));
        }
    }
    
    std::vector<int> result;
    
    // Step2 : Extract elements from the heap and add the next element from the corresponding array
    while(!minHeap.empty()) {
        Element curr = minHeap.top();
        minHeap.pop();
        
        // Add the smallest element to the result
        result.push_back(curr.value);
        
        // If the current array has more elements, insert the next element into the heap
        if(curr.indexInArr + 1 < arrays[curr.arrIndex].size()) {
            minHeap.push(Element(arrays[curr.arrIndex][curr.indexInArr + 1], curr.arrIndex, curr.indexInArr + 1));
        }
    }
    
    return result;
}


int main() {
    
    // K sorted arrays
    std::vector<std::vector<int>> arrays = {{1, 5, 9}, {12, 16, 23}, {2, 8, 15}};
    
    std::vector<int> res = mergeKSortedArrays(arrays);
    
    std::cout << "Merged sorted array: ";
    for(int num : res) {
        std::cout << num << " ";
    }
    std::cout << '\n';
    
    return 0;
}

/*
Output:
Merged sorted array: 1 2 5 8 9 12 15 16 23
*/
