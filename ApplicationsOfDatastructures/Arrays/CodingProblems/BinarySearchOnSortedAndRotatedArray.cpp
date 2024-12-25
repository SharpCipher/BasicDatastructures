/*
Search an element in a Sorted and Pivoted Array:
An element in a sorted array can be found in O(log n) time via binary search. But suppose we rotate an
ascending order sorted array at some pivot unknown to you beforehand. So for instance, 1 2 3 4 5 might
become 3 4 5 1 2. Devise a way to find an element in the rotated array in O(log n) time.
*/
#include <iostream>

int Bsearch(int arr[], int l, int h, int key) {
    if(l > h)
        return -1;
    int mid = (l+h)/2;
    if(arr[mid] == key)
        return mid;
    /* If arr[l...mid] is sorted */
    if(arr[l] <= arr[mid]) {
        /* As this subarray is sorted, we cab quickly
        check if key lies in this half or other half */
        if(key >= arr[l] && key <= arr[mid]) {
            return Bsearch(arr, l, mid-1, key);
        }
        return Bsearch(arr, mid+1, h, key);
    }

    /*
    If arr[l...mid] is not sorted, then arr[mid... r] must be sorted
    */
    if(key >= arr[mid] && key <= arr[h])
        return Bsearch(arr, mid+1, h, key);
    return Bsearch(arr, l, mid-1, key);
}

int main() {
    int arr[] = {4,5,6,7,8,9,1,2,3};
    int brr[] = {20,11,12,13,14,15,16,17,18};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    std::cout << "Enter the Key to be searched: ";
    std::cin >> key;

    int i = Bsearch(arr, 0, n-1, key);
    int j = Bsearch(brr, 0, n-1, key);

    if(i != -1)
        std::cout << "arr Index: " << i << '\n';
    else
        std::cout << key << " not found in arr\n";

    if(j != -1)
        std::cout << "brr Index: " << j << '\n';
    else
        std::cout << key << " not found in brr\n";
    return 0;
}
