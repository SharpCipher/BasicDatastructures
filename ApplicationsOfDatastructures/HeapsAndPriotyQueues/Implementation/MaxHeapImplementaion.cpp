#include <iostream>
#include <vector>

// Template for Max Heap representation
template <typename T>
class MaxHeap {
private:
    std::vector<T> array;
    int size;
    int capacity;

public:
    MaxHeap(int capacity) : size(0), capacity(capacity) {
        array.resize(capacity);
    }

    // Function to Heapify the node at index i
    void heapify(int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < size && array[left] > array[largest]) {
            largest = left;
        }

        if(right < size && array[right] > array[largest]) {
            largest = right;
        }

        if(largest != i) {
            std::swap(array[i], array[largest]);
            heapify(largest);
        }
    }

    // Function to build a max heap from the given array
    void buildHeap(const std::vector<T>& array) {
        capacity = array.size();
        size = array.size();

        // Build heap by rearranging the array
        for(int i = (size - 1) / 2; i >= 0; --i) {
            heapify(i);
        }        
    }

    // Function to insert a new element into the heap
    void insert(T value) {
        if(size == capacity) {
            array.resize(2*capacity);
            capacity *= 2;
        }
        size++;
        int i = size - 1;
        array[i] = value;

        // Fix the max heap property if it is violated (Heapify up)
        while(i != 0 && array[(i-1)/2] < array[i]) {
            std::swap(array[i], array[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    T extractMax() {
        if(size <= 0) {
            std::cout << "Heap is empty\n";
            return -1;
        }

        if(size == 1) {
            size--;
            return array[0];
        }

        T maxElement = array[0];

        // Move the last element to the root
        array[0] = array[size-1];
        size--;

        // Heapify the root
        heapify(0);

        return maxElement;

    }

    void print() const {
        std::cout << "Max Heap: ";
        for(int i=0; i<size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << '\n';
    }
};

int main()
{
    MaxHeap<int> maxHeap(10);
    std::vector<int> arr = {10, 20, 15, 12, 40, 25, 18};

    maxHeap.buildHeap(arr);
    maxHeap.print();
    maxHeap.insert(50);
    maxHeap.print();
    maxHeap.insert(16);
    maxHeap.extractMax();
    maxHeap.print();
    maxHeap.insert(30);
    maxHeap.extractMax();
    maxHeap.print();

    return 0;
}