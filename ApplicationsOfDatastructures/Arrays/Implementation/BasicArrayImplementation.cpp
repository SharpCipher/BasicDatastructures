#include <iostream>

class Array {
    int* data;
    int size;

    public:
        Array(int size) : size(size) {
            data = new int[size];
        }
        ~Array() {
            delete[] data;
        }
        int& operator[](int index) {
            if(index < 0 || index >= size) {
                throw std::out_of_range("Index out of range!!");
            }
            return data[index];
        }

        int getSize() const {
            return size;
        }
};

int main() {
    Array arr(10);
    for(int i=0; i<arr.getSize(); ++i) {
        arr[i] = i*10+2;
    }
    for(int i=0; i<arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    //std::cout << arr[12] << "::::\n";
    std::cout << '\n';

    return 0;
}