class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = INT_MIN;
        vector<bool> res(candies.size());
        for(const auto& x : candies) {
            if(max <= x) {
                max = x;
            }
        }
        for(int i=0; i<candies.size(); ++i) {
            if((candies[i]+extraCandies) >= max) {
                res[i] = true; 
            }
            else {
                res[i] = false;
            }
        }

        return res;
    }
};