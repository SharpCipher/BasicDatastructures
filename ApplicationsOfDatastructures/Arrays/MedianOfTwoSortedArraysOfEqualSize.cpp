/*
There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the array
obtained after merging the above 2 arrays(i.e. array of length 2n). The complexity should be O(log(n))
Assumption: Both arrays are sorted and of equal size.
*/
#include <iostream>

int getMedian(int arr1[], int arr2[], int n) {
    int i = 0; //current index of arr1
    int j = 0; //current index of arr2
    int count;
    int med1 = -1, med2 = -1;

    /* Since there are 2n elements, median will be average of elements at index n-1 and
    n in the array obtained after merging ar1 and ar2 */
    for(count = 0; count <= n; ++count) {
        
        // All elements of arr1 is smaller than first element(which is the smallest in arr2) of arr2
        if(i == n) {
            med1 = med2; // Store the previous median
            med2 = arr2[0];
            break;
        }
        // All elements of arr2 is smaller than first element of arr1
        else if(j == n) {
            med1 = med2;
            med2 = arr1[0];
            break;
        }

        if(arr1[i] < arr2[j]) {
            med1 = med2;
            med2 = arr1[i];
            i++;
        }
        else {
            med1 = med2;
            med2 = arr2[j];
            j++;
        }
    }

    return (med1+med2)/2;
}

int main() {
    int arr1[] = {1, 12, 15, 26, 38};
    int arr2[] = {2, 13, 17, 30, 45};

    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    if(n1 == n2) {
        std::cout << "Median is: " << getMedian(arr1, arr2, n1) << '\n';
    }
    else {
        std::cout << "Arrays should be of equal size" << '\n';
    }
    return 0;
}