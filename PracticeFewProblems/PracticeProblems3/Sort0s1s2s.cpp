#include <iostream>
#include <vector>

void sort012(std::vector<int>& arr){
    int n = arr.size();
    int low = 0, mid = 0, high = n-1;

    while(mid <= high) {
        if(arr[mid] == 0) {
            std::swap(arr[low++], arr[mid++]);
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else {
            std::swap(arr[mid], arr[high--]);
        }
    }
}

int main()
{
    std::vector<int> arr1 = {0, 1, 2, 0, 1, 2};
    sort012(arr1);

    std::cout << "Sorted array1: ";
    for(int i = 0; i < arr1.size(); i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr2 = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    sort012(arr2);
    std::cout << "Sorted array2: ";
    for(int i = 0; i < arr2.size(); i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr3 = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2};
    sort012(arr3);
    std::cout << "Sorted array3: ";
    for(int i = 0; i < arr3.size(); i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
Output:
Sorted array1: 0 0 1 1 2 2
Sorted array2: 0 0 0 1 1 1 2 2 2
Sorted array3: 0 0 0 0 1 1 1 1 2 2 2 2

Time Complexity: O(n)
Space Complexity: O(1)

Explanation:
1. We will use three pointers low, mid and high.
2. low will point to the start of the array, mid will point to the start of the array and high will point to the end of the array.
3. We will iterate through the array and check the value at mid.
4. If the value at mid is 0, we will swap the value at low and mid and increment both low and mid.
5. If the value at mid is 1, we will increment mid.
6. If the value at mid is 2, we will swap the value at mid and high and decrement high. We will not increment mid as we need to check the value at mid after swapping.
7. We will repeat the above steps until mid is less than or equal to high.
8. Finally, the array will be sorted in the order of 0s, 1s and 2s.

*/