/*
Problem Description

Given a sorted array A containing N integers both positive and negative.

You need to create another array containing the squares of all the elements in A and return it in non-decreasing order.

Try to this in O(N) time.

Example Input

Input 1:

 A = [-6, -3, -1, 2, 4, 5]

Input 2:

 A = [-5, -4, -2, 0, 1]

Example Output

Output 1:

 [1, 4, 9, 16, 25, 36]

Output 2:

 [0, 1, 4, 16, 25]

*/

vector<int> Solution::solve(vector<int> &A) {
    vector<int> v;
    int n = A.size();

    for(int i=0; i<n; i++){
        int j = A[i]*A[i];
        v.push_back(j);
    }
    sort(v.begin(), v.end());
    return v;
}
