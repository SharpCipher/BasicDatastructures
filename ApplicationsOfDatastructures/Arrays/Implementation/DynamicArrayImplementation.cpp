#include <iostream>
#include <cassert>

class DynamicArray {
    private:
        int* data;
        int size;
        int capacity;
        void resize() {
            capacity *= 2;
            int* newData = new int[capacity];
            for(size_t i=0; i<size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }

        public:
            DynamicArray() : size(0), capacity(1) {
                data = new int[capacity];
            }

            ~DynamicArray() {
                delete[] data;
            }

            void addElement(int element) {
                if(size == capacity){
                    resize();
                }
                assert(size >= 0 && size < capacity);
                data[size++] = element;
            }

            void print() const {
                for(int i=0; i<size; ++i) {
                    std::cout << data[i] << " ";
                }
                std::cout << '\n';
            }
};
int main()
{
    DynamicArray arr;
    arr.addElement(5);
    arr.addElement(56);
    arr.print();

    return 0;
}