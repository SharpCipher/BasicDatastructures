/*
You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.
Note:
Each pair should be sorted i.e the first value should be less than or equals to the second value. 

Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value, the pair with a smaller second value should come first.

Sample Input 1:
5 5
1 2 3 4 5
Sample Output 1:
1 4
2 3
Explaination For Sample Output 1:
Here, 1 + 4 = 5
      2 + 3 = 5
Hence the output will be, (1,4) , (2,3).
Sample Input 2:
5 0
2 -3 3 3 -2
Sample Output 2:
-3 3
-3 3
-2 2

*/

#include <iostream>
#include <vector>

void pairSum(std::vector<int>& arr, int n, int s) {
    std::vector<std::vector<int>> res;

    // Sort the array
    std::sort(arr.begin(), arr.end());

    // Use two pointers to find pairs
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(arr[i] + arr[j] == s) {
                res.push_back({arr[i], arr[j]});
            }
            // Break inner loop if sum becomes greater than s (as array is sorted)
            else if(arr[i] + arr[j] > s) {
                break;
            }
        }
    }

    // Sort the pairs
    std::sort(res.begin(), res.end(), [](std::vector<int>& a, std::vector<int>& b) {
        if(a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    });

    // Print the pairs
    for(auto& p : res) {
        std::cout << p[0] << " " << p[1] << std::endl;
    }
}

int main()
{
    std::vector<int> arr = {-3, -2, 2, 3, 3, 3};
    int n = arr.size();
    int s;
    std::cin >> s;
    pairSum(arr, n, s);

    return 0;
}