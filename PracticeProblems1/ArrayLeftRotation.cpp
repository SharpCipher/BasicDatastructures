/*

A left rotation operation on an array of size n shifts each of the array's elements 1 unit to the left.
Given an integer,d, rotate the array that many steps left and return the result. 

Sample Input

5 4
1 2 3 4 5

Sample Output

5 1 2 3 4

To perform d=4 left rotations, the array undergoes the following sequence of changes: 

[1,2,3,4,5]--->[2,3,4,5,1].....[5,1,2,3,4]

@HackerRank
*/

vector<int> rotateLeft(int d, vector<int> arr) {
    vector<int> num;
    for(int i=0; i<d; i++){
        num.push_back(arr[i]);
    }
    for(int i=d; i<arr.size(); i++){
        arr[i-d] = arr[i];
    }
    for(int i=0; i<num.size(); i++){
        arr[arr.size()-d+i] = num[i];
    }
    return arr;
}