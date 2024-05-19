/*

Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.

*/

int Solution::firstMissingPositive(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    int j = 1;
    for(int i=0; i<n; i++){
        if(A[i]>0){
            if(A[i] != j){
                break;
            }
            j++;
        }

    }
    return j;
}
