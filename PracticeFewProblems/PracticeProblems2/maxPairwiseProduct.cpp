#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int64_t MaxPairwiseProduct(const vector<int64_t>& arr){
    int64_t firstMax = 0, Secondmax = 0;
    int n = arr.size();
    for(int i=0; i<n; i++){
        if(arr[i] > firstMax){
            Secondmax = firstMax;
            firstMax = arr[i];
        }
        else if(arr[i] > Secondmax){
            Secondmax = arr[i];
        }
    }
    return firstMax*Secondmax;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int64_t> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers);
    return 0;
}