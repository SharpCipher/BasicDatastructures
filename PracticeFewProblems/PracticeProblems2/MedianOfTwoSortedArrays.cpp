/*

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

@LeetCode

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int merged_array_length = len1+len2;
        int median_index = merged_array_length/2;
        
        vector<double> merged(merged_array_length, 0);
        int i = 0, j = 0, k = 0;
        while(i<len1 && j<len2) {
            if(nums1[i]<=nums2[j]) merged[k++] = nums1[i++];
            else merged[k++] = nums2[j++]; 
        }
        while(i<len1) merged[k++] = nums1[i++];
        while(j<len2) merged[k++] = nums2[j++];
        // cout<<merged[median_index]<<endl;
        if(merged_array_length&1) return (double)merged[median_index];
        return ((double)merged[median_index-1]+(double)merged[median_index])/2.00;
    }
};