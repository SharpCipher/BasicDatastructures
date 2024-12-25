#include <iostream>
#include <iomanip>

void printMatrix(int **arr, int n) {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            std::cout <<std::setw(8)<< arr[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void rotateMatrix(int **arr, int n) {
    if(n == 0 || n == 1)
        return;
    for(int i=0; i<n; ++i) {
        for(int j=i; j<n; ++j) {
            std::swap(arr[j][i], arr[i][j]);
        }
    }

    int i = 0, j = 0, column = 0;
    while(column < n) {
        i = 0, j = n-1;
        while(i < j) {
            std::swap(arr[i][column], arr[j][column]);
            i += 1;
            j -= 1;
        }
        column += 1;
    }
}

int main() {
    int n;
    std::cin >> n;
    int **arr = new int*[n];
    for(int i = 0; i < n; ++i) {
        arr[i] = new int[n];
    }
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            std::cin >> arr[i][j];
        }
    }

    std::cout << "Input Matrix: \n";
    printMatrix(arr, n);
    
    rotateMatrix(arr, n);

    std::cout << "Output Matrix: \n";
    printMatrix(arr, n);

    for(int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}