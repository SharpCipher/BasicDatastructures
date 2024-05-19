/*

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        if(row == 0 || col == 0){
            return false;
        }
        
        int l = 0;
        int h = row*col-1;
        
        while(l <= h){
            int m = l+(h-l)/2;
            int index = matrix[m/col][m%col];
            if(target == index)
                return true;
            else if(target < index)
                h = m-1;
            else
                l = m+1;
        }
        
        return false;
    }
};