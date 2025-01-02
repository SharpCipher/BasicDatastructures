/*
Given an array arr[] of N distinct elements and a number K, where K is smaller than the size of the array. Find the K’th smallest element in the given array.

Examples:
Input: arr[] = {7, 10, 4, 3, 20, 15}, K = 3 
Output: 7


Input: arr[] = {7, 10, 4, 3, 20, 15}, K = 4 
Output: 10
*/

#include <iostream>
#include <vector>
#include <queue>

int kthSmallest(const std::vector<int>& arr, int k) {
    int n = arr.size();
    
    std::priority_queue<int> pq; // By default, it's max heap
    
    for(int i=0; i<n; ++i) {
        pq.push(arr[i]);
        
        // If the size of the max heap exceeds k, remove the largest element
        if(pq.size() > k) {
            pq.pop();
        }
    }
    
    // Return the Kth Smallest element which is top of the max heap
    return pq.top();
}

int main() {
    
    std::vector<int> arr = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10 };
    int k;
    std::cout << "K is ?\n";
    std::cin >> k;
    
    std::cout <<"Kth Smallest element is: " << kthSmallest(arr, k) << '\n';
    
    return 0;
}

/*
Output:
K is ?
3
Kth Smallest element is: 4
*/
