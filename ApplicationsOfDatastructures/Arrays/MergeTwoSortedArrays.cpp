/*
Given two sorted arrays A and B, find the merged sorted array C by merging A and B.

A: [1, 2, 3, 4, 4]
B: [2, 4, 5, 5]
C: [1, 2, 2, 3, 4, 4, 4, 5, 5]

*/
#include <iostream>
#include <vector>

std::vector<int> mergeTwoSortedArrays(std::vector<int> &A, std::vector<int> B) {
    // add your logic here
	int i=0, j=0, k=0;
	int n1 = A.size();
	int n2 = B.size();
	std::vector<int> C(n1+n2);
	while(i < n1 && j < n2) {
		if(A[i] < B[j]) {
			C[k] = A[i];
			++i;
		}
		else {
			C[k] = B[j];
			++j;
		}
		++k;
	}
	while(i < n1) {
		C[k++] = A[i++];
	}
	while(j < n2) {
		C[k++] = B[j++];
	}
	
	return C;
}
int main() {
    int n1, n2;
    std::cin>>n1>>n2;
    std::vector<int> A(n1);
    std::vector<int> B(n2);
    for(int i=0; i<n1; ++i) {
        std::cin >> A[i];
    }
    for(int i=0; i<n2; ++i) {
        std::cin >> B[i];
    }
    std::vector<int> res(n1+n2);
    res = mergeTwoSortedArrays(A, B);
    for(int i=0; i<n1+n2; ++i) {
        std::cout << res[i] << " ";
    }
    std::cout << '\n';
    return 0;
}