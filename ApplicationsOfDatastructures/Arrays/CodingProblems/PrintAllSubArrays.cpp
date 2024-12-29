#include <iostream>

void allSubArrays(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            for (int k = i; k <= j; ++k)
            {
                std::cout << arr[k] << " ";
            }
            std::cout << '\n';
        }
    }
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    allSubArrays(arr);

    return 0;
}