/*
In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into 
a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the 
number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original 
matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal,
output the new reshaped matrix; Otherwise, output the original matrix.

Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]

Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]

@LeetCode
*/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        if(m*n != r*c)
            return mat;
        vector<vector<int>> res(r, vector<int>(c));
        int row_iterator=0;
        int col_iterator=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[row_iterator][col_iterator]=mat[i][j];
                col_iterator++;   //fill column column first
                
                if(col_iterator==c){                  
                    col_iterator=0;
                    row_iterator++;   //then traverse to the rows 
                }
            }
            
        }
        return res;
        
    }
};