/*
Given an array arr[] of N distinct elements and a number K, where K is smaller than the size of the array. Find the K’th smallest element in the given array.

Examples:
Input: arr[] = {7, 10, 4, 3, 20, 15}, K = 3 
Output: 7


Input: arr[] = {7, 10, 4, 3, 20, 15}, K = 4 
Output: 10
*/

#include <iostream>
#include <vector>
#include <queue>

int kthSmallest(const std::vector<int>& arr, int k) {
    int n = arr.size();
    
    std::priority_queue<int> pq; // By default, it's max heap
    
    for(int i=0; i<n; ++i) {
        pq.push(arr[i]);
        
        // If the size of the max heap exceeds k, remove the largest element
        if(pq.size() > k) {
            pq.pop();
        }
    }
    
    // Return the Kth Smallest element which is top of the max heap
    return pq.top();
}

int main() {
    
    std::vector<int> arr = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10 };
    int k;
    std::cout << "K is ?\n";
    std::cin >> k;
    
    std::cout <<"Kth Smallest element is: " << kthSmallest(arr, k) << '\n';
    
    return 0;
}

/*
Output:
K is ?
3
Kth Smallest element is: 4


Notes:
### Why Use a Max Heap to Find the Kth Smallest Element?

The key observation is that in the given code, we're interested in finding the **Kth smallest element**, but the approach is based on maintaining the **top K smallest elements** in a data structure. A max heap is used in this approach because it allows us to efficiently remove the largest element when the heap exceeds size **K**.

### Here's how the code works with a max heap:

1. **Heap size limit**: We are trying to maintain the K smallest elements, so we use a max heap to keep track of these elements. The reason for using a **max heap** is that the largest element among the smallest K elements should always be at the **top** of the heap.
   
2. **Why max heap**:
   - We iterate through the entire array, adding elements one by one into the heap.
   - If the heap exceeds size **K** (after adding a new element), we **pop** the top element (the largest element in the heap).
   - This ensures that after processing all elements, the heap contains exactly **K smallest elements** from the array.
   - The **Kth smallest element** will be at the top of the heap (because the heap stores the smallest K elements, and the largest of those K elements is the Kth smallest element).

3. **Efficiency**: 
   - Pushing an element into a heap takes **O(log K)** time.
   - Removing the top element (i.e., popping) also takes **O(log K)** time.
   - Since we are iterating over all **N** elements in the array, the total time complexity is **O(N log K)**, which is efficient for large arrays when **K << N**.

### What Would Happen with a Min Heap?

If you were to use a **min heap** to find the Kth smallest element, you'd have to change the way you approach the problem. With a min heap:

- The smallest element would always be at the top.
- To find the **Kth smallest element**, you would have to **pop** the first **K-1 elements**, and then the top element after that would be the **Kth smallest element**.
- This approach would take **O(N log K)** to build the heap, but you would need to make **K pops** after that, which would take **O(K log K)** time. This could be less efficient if **K** is large compared to **N**.

### Key Difference in Approach:
- **Max heap**: You maintain the smallest **K** elements in the heap. After processing all elements, the **largest** of the smallest **K** elements (the Kth smallest element) is at the top of the heap.
- **Min heap**: You'd need to pop the first **K-1** smallest elements and then get the Kth element at the top, which might not be as direct or efficient for the specific task of finding the Kth smallest element.

### Example Walkthrough for the Max Heap Approach

Let's walk through an example to clarify the behavior of the **max heap** approach:

Array: `{ 10, 5, 4, 3, 48, 6, 2, 33, 53, 10 }`, with `K = 4` (we want to find the 4th smallest element).

1. **Insert 10**: The heap is `{10}`.
2. **Insert 5**: The heap is `{10, 5}`.
3. **Insert 4**: The heap is `{10, 5, 4}`.
4. **Insert 3**: The heap is `{10, 5, 4, 3}`.
5. **Insert 48**: The heap exceeds size K (5 elements). We remove the largest element, which is 10. The heap is `{5, 3, 4, 48}`.
6. **Insert 6**: The heap exceeds size K again. We remove the largest element, which is 48. The heap becomes `{6, 5, 4, 3}`.
7. **Insert 2**: The heap exceeds size K again. We remove the largest element, which is 6. The heap becomes `{5, 3, 4, 2}`.
8. **Insert 33**: The heap exceeds size K again. We remove the largest element, which is 5. The heap becomes `{4, 3, 2, 33}`.
9. **Insert 53**: The heap exceeds size K again. We remove the largest element, which is 33. The heap becomes `{4, 3, 2, 53}`.
10. **Insert 10**: The heap exceeds size K again. We remove the largest element, which is 53. The heap becomes `{4, 3, 2, 10}`.

At the end of the process, the heap contains `{4, 3, 2, 10}`, and the largest element in the heap is **10**, which is the **4th smallest element** in the array.

### Conclusion

- **Max heap** is used here because it helps us efficiently maintain the **smallest K elements** while iterating through the array. The largest element among these K elements is the **Kth smallest element**.
- Using a **min heap** would require popping the first **K-1** elements and may not be as efficient in this specific problem.

Thus, the **max heap** approach is optimal in this case for finding the **Kth smallest element**.
*/
