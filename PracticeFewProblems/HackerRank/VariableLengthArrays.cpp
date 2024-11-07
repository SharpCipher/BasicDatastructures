#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<int>> arr(n);

    for(int i=0; i<n; ++i) {
        int k;
        std::cin >> k;

        arr[i].resize(k);

        for(int j=0; j<k; ++j) {
            std::cin >> arr[i][j];
        }
    }

    while(q--) {
        int index1, index2;
        std::cin >> index1 >> index2;

        if(index1 >= 0 && index1 < n && index2 >= 0 && index2 < arr[index1].size()) {
            std::cout << arr[index1][index2] << '\n';
        }
    }

    return 0;
}

/*
Notes:

The code provided is a simple program that demonstrates working with a 2D vector (a vector of vectors) and 
processing multiple queries to retrieve specific elements from it. The program starts by reading two integers `n` and `q` from the input,
where `n` is the number of lists (or rows) in the 2D array and `q` is the number of queries.
It then constructs a 2D vector `arr` of size `n`, where each element is another vector. For each of the `n` rows,
the code reads an integer `k` (number of elements in the row) and then reads `k` integers to fill that particular row in the 2D vector.

After the 2D vector is populated, the program enters a loop to process `q` queries. 
Each query consists of two integers `index1` and `index2`, representing the row and column indices of
the element to retrieve. The program checks if these indices are valid (i.e., within bounds of the vector dimensions),
and if they are, it outputs the corresponding element from `arr[index1][index2]`. 
If the indices are out of bounds, the query is ignored. This approach allows handling dynamic-sized
rows in the 2D array and efficiently responding to multiple queries about specific elements.
*/