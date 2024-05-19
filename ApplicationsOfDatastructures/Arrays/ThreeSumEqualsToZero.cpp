/*
Given an array A, find all unique triplets in the array whose sum is equal to zero.
Each triplet should be sorted. The resultant array should be sorted as well.
A: [1, 1, 0, -1, -2]
Triplets: [
  [-2, 1, 1],
  [-1, 0, 1]
]
*/

#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> threeSumEqualToZero(std::vector<int>& nums, int n) {
    std::vector<std::vector<int>> res;
    
    // Sort the array
    sort(nums.begin(), nums.end());

    for(int i=0; i<n-2; ++i) {
        // Skip duplicates
        if(i>0 && nums[i] == nums[i-1])
            continue;
        int left = i+1;
        int right = n-1;

        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0) {
                res.push_back({nums[i], nums[left], nums[right]});

                // Skip the duplicates
                while(left < right && nums[left] == nums[left+1])
                    left++;
                while(left < right && nums[right] == nums[right-1])
                    right--;

                left++;
                right--;
            }
            else if(sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    return res;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for(int i=0; i<n; ++i) {
        std::cin>>nums[i];
    }
    std::vector<std::vector<int>> triplets = threeSumEqualToZero(nums, n);

    for(const auto& triplet : triplets) {
        std::cout << "[";
        for(int num : triplet) {
            std::cout << num << " ";
        }
        std::cout << "]";
    }
    std::cout << '\n';
    return 0;
}