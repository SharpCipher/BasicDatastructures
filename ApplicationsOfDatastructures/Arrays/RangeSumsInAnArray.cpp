#include <iostream>
#include <vector>

std::vector<int> rangeSums(const std::vector<int>& arr, const int n, const std::vector<std::pair<int, int>>& ranges) {
    std::vector<int> prefixSum(n+1, 0);
    std::vector<int> result;

    // Computing prefix sum
    for(int i=1; i<=n; ++i) {
        prefixSum[i] = prefixSum[i-1] + arr[i-1];
    }

    // Computing Sum for each range
    for(auto& r : ranges) {
        int left = r.first;
        int right = r.second;

        if(left >= 0 && right < n && left <= right) {
            int rangeSum = prefixSum[right+1] - prefixSum[left];
            result.push_back(rangeSum);
        }
        else {
            result.push_back(0);
        }
    }

    return result;
}

int main()
{
    int n,q;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    std::cout << "Enter " << n << " Elements: ";
    std::vector<int> arr(n);
    for(int i=0; i<n; ++i) {
        std::cin >> arr[i];
    }
    std::cout << "Enter the number of ranges: ";
    std::cin >> q;

    std::vector<std::pair<int, int>> ranges;
    std::cout << "Enter " << q << " ranges: \n";
    int left, right;
    for(int i=0; i<q; ++i) {
        std::cin >> left >> right;
        ranges.push_back({left, right});
    }
    std::cout << "Entered ranges: \n";
    for(int i=0; i<ranges.size(); ++i) {
        std::cout << ranges[i].first << " " << ranges[i].second << '\n';
    }

    std::vector<int> res;
    res = rangeSums(arr, n, ranges);
    for(int i=0; i<n; ++i) {
        std::cout << res[i] << " ";
    }
    std::cout << '\n';

    return 0;
}