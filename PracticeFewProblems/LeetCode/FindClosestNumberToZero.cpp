/*
Given an integer array nums of size n, return the number with the value closest to 0 in nums.
If there are multiple answers, return the number with the largest value.

Example 1:

Input: nums = [-4,-2,1,4,8]
Output: 1
Explanation:
The distance from -4 to 0 is |-4| = 4.
The distance from -2 to 0 is |-2| = 2.
The distance from 1 to 0 is |1| = 1.
The distance from 4 to 0 is |4| = 4.
The distance from 8 to 0 is |8| = 8.
Thus, the closest number to 0 in the array is 1.

Example 2:

Input: nums = [2,-1,1]
Output: 1
Explanation: 1 and -1 are both the closest numbers to 0, so 1 being larger is returned.

*/

#include <iostream>
#include <vector>

int main() {

    std::vector<int> nums = {-4,-2,1,4,8};
    int n = nums.size();

    int dist;
    int min = INT_MAX;

    std::vector<int> res;
    for(int i = 0; i < n; ++i) {
       dist = abs(nums[i]);
       if(dist < min) {
            min = dist;
       }
    }

    for(int i=0; i<n; ++i) {
        if(abs(nums[i]) == min) {
            res.push_back(nums[i]);
        }
    }
    std::cout << *max_element(res.begin(), res.end()) << '\n';

    return 0;
}