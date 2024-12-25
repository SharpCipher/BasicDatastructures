/*
The array X is a mountain array if and only if n >= 3 and there exists some i (0 < i < n -1)
such that: X[0] < X[1] <...< X[i-1] < X[i] and X[i] > X[i+1] > ...> X[n-1]. In other words,
the array is a valid mountain when it is first strictly increasing and then strictly decreasing.

Examples:
Input: X[] = [5, 2, 1, 4], Output: false
Input: X[] = [5, 8, 8], Output: false
Input: X[] = [1, 2, 6, 5, 3], Output: true
*/
#include <iostream>
#include <vector>

// Method1: Traversing from left to right
bool isValidMountain1(const std::vector<int>& input, const int n) {
    int climb = 0;

    // Find the peak of the mountain : Travers up till peak
    while(climb < n-1 && input[climb] < input[climb+1]) {
        climb += 1;
    }

    // Return false if the Peak is at the beginning or at the end
    if(climb == 0 || climb == (n-1)) {
        return false;
    }

    // Travers down the mountain
    while(climb < n-1 && input[climb] > input[climb+1]){
        climb += 1;
    }

    if(climb == n-1) {
        return true;
    }
    else {
        return false;
    }
}

// Method2: Traversing from opposite ends
bool isValidMountain2(const std::vector<int>& input, int n) {
    int left = 0;
    int right = n-1;

    // Traverse up the mountain from left to right
    while(left < (n-1) && input[left] < input[left+1]) {
        left += 1;
    }

    // Traverse up the mountain from right to left
    while(right > 0 && input[right] < input[right-1]) {
        right -= 1;
    }

    // Check if both pointers meet at the same peak
    if((left > 0 ) && (left == right) && (right < (n-1))) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int n;
    std::cin >> n;
    int elem;
    std::vector<int> input;
    for(int i=0; i<n; ++i) {
        std::cin >> elem;
        input.push_back(elem);
    }
    // Approach1
    std::cout << "Is Valid Mountain: " << isValidMountain1(input, n) << '\n';

    // Approach2
    std::cout << "Is Valied Mountain: " << isValidMountain2(input, n) << '\n';

    return 0;
}
