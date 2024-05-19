#include <iostream>
#include <vector>

void intersectionOfTwoSortedArrays(const std::vector<int>& arr1, int n1, const std::vector<int>& arr2, int n2) {

    std::vector<int> res;
    int i=0, j=0, k=0;
    while(i<n1 && j<n2) {
        if(arr1[i] == arr2[j]) {
            if(res.empty() || res.back() != arr1[i]) {
                res.push_back(arr1[i]);
            }
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    for(int i=0; i<res.size(); ++i) {
        std::cout << res[i] << " ";
    }
    std::cout << '\n';
}

int main()
{
    int n1, n2;
    std::cin >> n1 >> n2;
    std::vector<int> arr1(n1);
    std::vector<int> arr2(n2);
    for(int i=0; i<n1; ++i)
        std::cin >> arr1[i];
    for(int i=0; i<n2; ++i)
        std::cin >> arr2[i];

    intersectionOfTwoSortedArrays(arr1, n1, arr2, n2);

    return 0;
}
