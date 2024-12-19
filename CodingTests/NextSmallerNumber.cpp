/*

Given a positive sorted array: [ 3, 4, 6, 9, 10, 12, 14, 15, 17, 19, 21 ]
Define a function f(a, x) that returns x, the next smallest number, or -1 for errors.

i.e.

f(a, 12) = 12
f(a, 13) = 12

*/

#include <iostream>
#include <vector>

int nextSmallestNumber(const std::vector<int>& arr, int x) {
    int n = arr.size();
    if(n == 0) {
        return -1;
    }
    
    int res = -1;
    int start = 0;
    int end = n - 1;
    
    while(start <= end) {
        int mid = (start + end)/ 2;
        
        if(arr[mid] == x) {
            return arr[mid];
        }
        else if(arr[mid] < x) {
            res = arr[mid];
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    
    return res;
}

int main()
{
    std::vector<int> arr = {3, 4, 6, 9, 10, 12, 14, 15, 17, 19, 21};
    int x;
    std::cin >> x;
    int res = nextSmallestNumber(arr, x);
    std::cout << res << '\n';
    return 0;
}
