#include <iostream>
#include <vector>
#include <unordered_map>

std::pair<int, int> twoSum(const std::vector<int>& arr, int t) {
    std::unordered_map<int, int> seen;
    for(int i = 0; i < arr.size(); ++i) {
        if(seen.count(t - arr[i])) {
            return {seen[t - arr[i]], i};
        }

        seen[arr[i]] = i;
    }

    return {-1, -1};

}

int main() {
    std::vector<int> arr = {3, 4, 3, 7, 2, 8, 5, 9, 2};
    int target = 4;

    std::pair<int, int> res = twoSum(arr, target);

    if(res.first == -1 && res.second == -1) {
        std::cout << "No such pair found that sums up to " << target << '\n';
    }
    else {
        std::cout << "Indices: " << res.first << " " << res.second << '\n';
    }

    return 0;
}