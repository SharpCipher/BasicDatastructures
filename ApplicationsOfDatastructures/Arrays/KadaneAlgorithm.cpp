/*
The sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum

Simple idea of the Kadane's algorithm is to look for all positive contiguous segments of the array
(max_ending_here is used for this). And keep track of maximum sum contiguous segment among all positive segments
(max_so_far is used for this). Each time we get a positive sum compare it with max_so_far and update max_so_far
if it is greater than max_so_far
*/
#include <iostream>

int maxSubArraySum(int arr[], int size) {
    int max_sum_so_far = INT_MIN, max_sum_ending_here = 0;
    for(int i=0; i<size; ++i) {
        max_sum_ending_here += arr[i];
        if(max_sum_so_far < max_sum_ending_here)
            max_sum_so_far = max_sum_ending_here;
        if(max_sum_ending_here < 0)
            max_sum_ending_here = 0;
    }
    return max_sum_so_far;
}

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    for(int i=0; i<n; ++i) {
        std::cin >> arr[i];
    }
    std::cout << "Maximum Sub Array Sum: "<< maxSubArraySum(arr, n) << '\n';
    return 0;
}
