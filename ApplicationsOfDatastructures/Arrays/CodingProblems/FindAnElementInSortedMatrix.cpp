/*
Given an n x m array where all rows and columns are in sorted order,
write a function to determine whether the array contains an element x

[1,  2,  3,  4]
[5,  6,  7,  8]
[9, 10, 11, 12]

x = 6 => searchElement function should return true
*/

#include <iostream>
#include <vector>

bool searchElement(std::vector<std::vector<int>>& matrix, int n, int m, int x) {
    // Start from the top-right corner
    int row = 0;
    int col = m-1;
    
    // Traverse the matrix
    while(row < n && col >= 0) {
        if(matrix[row][col] == x) {
            return true;
        }
        else if(matrix[row][col] > x) {
            col--;
        }
        else {
            row++;
        }
    }
    
    return false;
}

int main() {
    std::vector<std::vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    
    int x = 11;
    if(searchElement(arr, 3, 4, x)) {
        std::cout << "Element " << x << " is present in the matrix\n";
    }
    else {
        std::cout << "Element " << x << " is not present in the matrix\n";
    }
    
    x = 25;
    if(searchElement(arr, 3, 4, x)) {
        std::cout << "Element " << x << " is present in the matrix\n";
    }
    else {
        std::cout << "Element " << x << " is not present in the matrix\n";
    }
    
    return 0;
}

/*
Output:
Element 11 is present in the matrix
Element 25 is not present in the matrix
*/
