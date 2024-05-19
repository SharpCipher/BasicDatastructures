/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color
are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
*/
#include <iostream>
#include <cstdlib>
#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int l = 0, m = 0, r = nums.size()-1;
        while(m <= r){
            if(nums[m] == 0){
                std::swap(nums[l], nums[m]);
                l++;
                m++;
            }
            else if(nums[m] == 1){
                m++;
            }
            else {
                std::swap(nums[m], nums[r]);
                r--;
            }
        }
        for(int i=0; i<nums.size(); ++i){
            std::cout<<nums[i]<<" ";
        }
        std::cout<<std::endl;
    }
};

int main() {
    std::vector<int> input;
    for(int i=0; i<8; i++){
        input.push_back(rand()%3);
        std::cout<<input[i]<<" ";
    }
    std::cout<<std::endl;

    Solution s1;
    s1.sortColors(input);
    return 0;
}