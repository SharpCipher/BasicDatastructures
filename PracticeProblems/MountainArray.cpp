/*

Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

    arr.length >= 3
    There exists some i with 0 < i < arr.length - 1 such that:
        arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
        arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Example 1:

Input: arr = [2,1]
Output: false

Example 2:

Input: arr = [3,5,5]
Output: false

Example 3:

Input: arr = [0,3,2,1]
Output: true

@LeetCode
*/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        
        if(n < 3){
            return false;
        }
        
        int f = false;
        int c = 0, u = 0;
        
        for(int i = 1; i < arr.size()-1; i++){
            if(arr[i] == arr[i-1] || arr[i] == arr[i+1])
                return false;
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
                c++, f = true;
            if(arr[i] < arr[i-1] && arr[i] < arr[i+1])
                u++;
        }
        
        return (f && c == 1 && u == 0);
        
        
    }
};