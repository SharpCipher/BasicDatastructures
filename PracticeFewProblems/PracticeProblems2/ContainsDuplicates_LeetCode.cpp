class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         int n = nums.size();
         unordered_set<int> s;
         for(int i=0; i<n; i++){
             s.insert(nums[i]);
         }
         return !(s.size() == n);
        }
};