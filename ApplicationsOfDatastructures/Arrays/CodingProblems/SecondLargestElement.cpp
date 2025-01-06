/*
Get the second largest number of the array list.
-> Handle duplicates and cases with all equal elements
arr = {3, 3, 3, 3, 3, 3, 3} => No second maximum element
*/

#include <iostream>
#include <vector>
#include <climits>

int getTheSecondLargestElement(const std::vector<int>& arr) {
    int n = arr.size();
    int max = INT_MIN;
    int second_max = INT_MIN;
    if(n < 2) {
        std::cout << "Not enough elements to find the second largest\n";
        return -1;
    }
    for(int i=0; i<n; ++i) {
        if(arr[i] > max) {
            second_max = max;
            max = arr[i];
        }
        else if(arr[i] > second_max && arr[i] != max) {
            second_max = arr[i];
        }
    }
    if(second_max == INT_MIN) {
        std::cout << "There is no second maximum\n";
        return -1;
    }
    return second_max;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 3, 2, -1, -10};
    int res = getTheSecondLargestElement(arr);
    
    if(res != -1) {
        std::cout << "Second Max element: " << res << '\n';   
    }
    
    return 0;
}

/*
Output:
Second Max element: 2
*/
