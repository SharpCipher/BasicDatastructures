#include <iostream>
#include <vector>
#include <climits>

double findMedianOfSortedArrays(const std::vector<int>& input1, const std::vector<int>& input2) {
    int s1 = input1.size();
    int s2 = input2.size();

    // Ensure input1 is smaller of equal in size
    if(s1 > s2) {
        return findMedianOfSortedArrays(input2, input1);
    }

    int low = 0, high = s1;

    // Perform Binary search
    while(low <= high) {
        // Partition the smaller array
        int partitionX = (low + high)/2;

        // Calculate the corresponding partition for the larger array
        int partitionY = (s1 + s2 + 1)/2 - partitionX;

        // Determine the elements around the partition
        int max1 = (partitionX == 0) ? INT_MIN : input1[partitionX - 1];
        int min1 = (partitionX == s1) ? INT_MAX : input1[partitionX];

        int max2 = (partitionY == 0) ? INT_MIN : input2[partitionY - 1];
        int min2 = (partitionY == s2) ? INT_MAX : input2[partitionY];

        if(max1 <= min2 && max2 <= min1) {
            if((s1+s2)%2 == 0) {
                return (std::max(max1, max2) + std::min(min1, min2))/2.0;
            }
            else {
                return std::max(max1, max2);
            }
        }
        else if(max1 > min2) {
            high = partitionX - 1;
        }
        else {
            low = partitionX + 1;
        }
    }
    throw std::invalid_argument("Input arrays are not sorted or do not overlap");
}

int main() {
    std::vector<int> arr1 = {1, 12, 15, 26, 38};
    std::vector<int> arr2 = {2, 13, 17, 30, 45};
    std::vector<int> arr3 = {2, 13, 30};

    double medianOfEqualSizeArrays = findMedianOfSortedArrays(arr1, arr2);
    double medianOfUnequalSizeArrays = findMedianOfSortedArrays(arr1, arr3);

    std::cout << medianOfEqualSizeArrays << '\n';
    std::cout << medianOfUnequalSizeArrays << '\n';


    return 0;
}