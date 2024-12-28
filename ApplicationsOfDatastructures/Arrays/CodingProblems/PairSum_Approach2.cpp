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
#include <algorithm>

using namespace std;

vector<pair<int, int>> pairSum(vector<int> &arr, int S) {
    vector<pair<int, int>> result;
    int n = arr.size();
    
    // Sort the array to ensure pairs are in non-decreasing order
    sort(arr.begin(), arr.end());
    
    // Use two pointers to find pairs
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == S) {
            result.push_back({arr[left], arr[right]});
            left++;
            right--;
        } else if (sum < S) {
            left++;
        } else {
            right--;
        }
    }
    
    return result;
}

int main() {
    int n, S;
    cin >> n >> S;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<pair<int, int>> result = pairSum(arr, S);
    for (auto &p : result) {
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}