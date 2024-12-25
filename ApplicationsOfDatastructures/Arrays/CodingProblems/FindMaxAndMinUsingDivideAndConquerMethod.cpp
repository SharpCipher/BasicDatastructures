#include <iostream>

int* findMinMax(int input[], int l, int r) {
    int* minMax = new int[2];
    
    if(l == r) {    // Only one element in the array
        minMax[0] = input[l];  // min
        minMax[1] = input[r];  // max
    }
    else if(l+1 == r) {      // Two elements in the array
        if(input[l] < input[r]) {
            minMax[0] = input[l];
            minMax[1] = input[r];
        }
        else {
            minMax[0] = input[r];
            minMax[1] = input[l];
        }
    }
    else {
        int mid = l + (r - l) / 2;
        int* leftMinMax = findMinMax(input, l, mid);
        int* rightMinMax = findMinMax(input, mid + 1, r);
        
        // Finding minimum and maximum of left and right halves
        minMax[0] = std::min(leftMinMax[0], rightMinMax[0]); // min
        minMax[1] = std::max(leftMinMax[1], rightMinMax[1]); // max
        
        delete[] leftMinMax;
        delete[] rightMinMax;
    }

    return minMax;
}

int main() {
    int n;
    std::cin >> n;
    int* arr = new int[n];
    
    for(int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    
    int* res = findMinMax(arr, 0, n - 1);
    std::cout << "Min: " << res[0] << '\n' << "Max: " << res[1] << '\n';
    
    delete[] arr;
    delete[] res;
    
    return 0;
}