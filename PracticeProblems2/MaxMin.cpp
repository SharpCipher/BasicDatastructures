/*Given an array A of size N. You need to find the sum of Maximum and Minimum element in the given array.

NOTE: You should make minimum number of comparisons.

Example Input

Input 1:

 A = [-2, 1, -4, 5, 3]

Input 2:

 A = [1, 3, 4, 1]



Example Output

Output 1:

 1

Output 2:

 5
*/

int Solution::solve(vector<int> &A) {
    int min = A[0];
    int max = A[0];

    for(int i=1; i<A.size(); i++){
        if(A[i] < min){
            min = A[i];
        }
    }
    for(int i=1; i<A.size(); i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return min+max;
}


