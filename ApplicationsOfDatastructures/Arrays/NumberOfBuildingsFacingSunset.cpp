/*
Given an input array height[] representing the heights of buildings, write a program to count the
number of buildings facing the sunset. It is assumed that the heights of all buildings are distinct.

Examples
Input: height[] = [7, 4, 8, 2, 9], Output: 3 Explanation: As 7 is the first element, it can see the sunset.
Similarly, 8 and 9 can see the sunset. 4 and 2 can't see the sunset because 7 and 8 are hiding it.

Input: height[] = [2, 3, 4, 5], Output: 4
*/

#include <iostream>
int facingSunCount(int height[], const int n) {
    int currMaxHeight = height[0];
    int buildingCount = 1;
    for(int i=1; i<n; ++i) {
        if(currMaxHeight < height[i]) {
            buildingCount++;
            currMaxHeight = height[i];
        }
    }

    return buildingCount;
}

int main() {
    int n;
    std::cin >> n;
    int *height = new int[n];
    for(int i=0; i<n; ++i) {
        std::cin >> height[i];
    }
    int count = facingSunCount(height, n);

    std::cout << "No.of buildings facing sun: "<< count << std::endl;

    return 0;
}