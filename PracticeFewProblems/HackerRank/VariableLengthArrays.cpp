#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<int>> arr(n);

    for(int i=0; i<n; ++i) {
        int k;
        std::cin >> k;

        arr[i].resize(k);

        for(int j=0; j<k; ++j) {
            std::cin >> arr[i][j];
        }
    }

    while(q--) {
        int index1, index2;
        std::cin >> index1 >> index2;

        if(index1 >= 0 && index1 < n && index2 >= 0 && index2 < arr[index1].size()) {
            std::cout << arr[index1][index2] << '\n';
        }
    }

    return 0;
}