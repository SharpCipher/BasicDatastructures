#include <iostream>
#include <stdexcept>

class Dynamic2DArray {
    private:
        int** data;
        int rows;
        int cols;

        // Function to allocate memory for the 2D array
        void allocate() {
            data = new int*[rows]; // Allocate memory for row pointers
            for(int i=0; i<rows; ++i) {
                data[i] = new int[cols]; // Allocate memory for each row
            }
        }

        // Function to deallocate memory for the 2D array
        void deallocate() {
            for(int i=0; i<rows; ++i) {
                delete[] data[i];  // Deallocate memory for each row
            }
            delete[] data;  // Deallocate memory for row pointers
        }

    public:
        
        // Constructor to initialize the 2D array with given dimensions
        Dynamic2DArray(int rows, int cols) : rows(rows), cols(cols) {
            allocate();
        }

        // Destructor to free the allocated memory
        ~Dynamic2DArray() {
            deallocate();
        }

        // Method to resize the 2D array
        void resize(int newRows, int newCols) {
            
            // Allocate new memory
            int** newData = new int*[newRows];
            for(int i=0; i<newRows; ++i) {
                newData[i] = new int[newCols];
            }

            // Copy old data to new array
            int minRows = (newRows < rows) ? newRows : rows;
            int minCols = (newCols < cols) ? newCols : cols;

            for(int i=0; i<minRows; ++i) {
                for(int j=0; j<minCols; ++j) {
                    newData[i][j] = data[i][j];
                }
            }
            
            // Deallocate old memory
            deallocate();

            // Update the data pointers and dimensions
            data = newData;
            rows = newRows;
            cols = newCols;
        }

        // Method to set the value at a specific location
        void setValue(int row, int col, int value) {
            if(row >= 0 && row < rows && col < cols && col >= 0) {
                data[row][col] = value;
            }
            else {
                throw std::out_of_range("Index out of range!\n");
            }
        }

        // Method to get the value at a specific location
        int getValue(int row, int col) const {
            if(row >= 0 && row < rows && col < cols && col >= 0) {
                return data[row][col];
            }
            else {
                throw std::out_of_range("Index out of range!\n");
            }
        }

        // Method to print the 2D array
        void print() const {
            for(int i=0; i<rows; ++i) {
                for(int j=0; j<cols; ++j) {
                    std::cout << data[i][j] << " ";
                }
                std::cout << '\n';
            }

        }
};

int main()
{
    
    Dynamic2DArray arr(3, 4);

    for(int i=0; i<3; ++i) {
        for(int j=0; j<4; ++j) {
            arr.setValue(i, j, i*4+j);
        }
    }

    std::cout << "Initial array: \n";
    arr.print();

    arr.resize(5, 6);

    std::cout << "Resized array: \n";
    arr.print();
    
    return 0;
}