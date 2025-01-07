# Mastering Heaps and Priority Queues in C++

Heaps and Priority Queues are fundamental data structures widely used in algorithms, such as Dijkstra's algorithm for shortest paths, Huffman encoding, and various scheduling problems. In this guide, we will cover everything you need to understand these concepts in-depth, along with practical C++ implementations.

### Table of Contents:
1. **Introduction to Heaps**
    - What is a Heap?
    - Types of Heaps
    - Properties of Heaps
2. **Binary Heap Representation**
    - Array Representation of Heaps
    - Inserting and Deleting Elements
    - Time Complexity of Operations
3. **Priority Queue**
    - What is a Priority Queue?
    - Binary Heap as Priority Queue
    - C++ Standard Library: `priority_queue`
4. **Heap Operations**
    - Heapify
    - Extract Max/Min
    - Insertion
5. **Advanced Topics**
    - D-ary Heap
    - Fibonacci Heap

6. **Use Cases and Applications**

---

### 1. Introduction to Heaps

#### What is a Heap?

A **Heap** is a complete binary tree-based data structure that satisfies the heap property. In simpler terms, a heap is a tree in which every parent node has a value greater (in case of a max-heap) or smaller (in case of a min-heap) than its children.

#### Types of Heaps

1. **Max-Heap**: In a max-heap, the key of each node is greater than or equal to the keys of its children. This property must hold for all nodes in the heap.

    **Max-Heap Example:**
    ```
              10
             /  \
            7    5
           / \  / \
          2  3 4   1
    ```

2. **Min-Heap**: In a min-heap, the key of each node is less than or equal to the keys of its children.

    **Min-Heap Example:**
    ```
              1
             / \
            2   3
           / \ / \
          4  5 6  7
    ```

#### Heap Properties

- **Complete Binary Tree**: A heap is always a complete binary tree, meaning every level is fully filled except possibly the last level, which is filled from left to right.
- **Heap Property**: 
    - In a **max-heap**, each parent is greater than or equal to its children.
    - In a **min-heap**, each parent is less than or equal to its children.

---

### 2. Binary Heap Representation

Heaps are typically implemented using **arrays** or **vectors** because it allows for efficient storage and manipulation.

#### Array Representation of Heaps

In an array-based heap:
- The **root** is at index 0.
- For a node at index `i`:
  - The **left child** is at index `2*i + 1`.
  - The **right child** is at index `2*i + 2`.
  - The **parent** is at index `(i-1)/2`.

##### Example of Max-Heap in an Array

Consider the following max-heap:

```
              10
             /  \
            7    5
           / \  / \
          2  3 4   1
```

This heap can be represented as an array:

```
[10, 7, 5, 2, 3, 4, 1]
```

- Index 0: 10 (root)
- Index 1: 7 (left child of 10)
- Index 2: 5 (right child of 10)
- Index 3: 2 (left child of 7)
- Index 4: 3 (right child of 7)
- Index 5: 4 (left child of 5)
- Index 6: 1 (right child of 5)

---

### 3. Priority Queue

A **Priority Queue** is a type of abstract data type that supports efficient retrieval of the highest (or lowest) priority element. The main difference between a regular queue and a priority queue is that in a priority queue, each element is associated with a priority value, and the element with the highest priority is dequeued first.

In most implementations, **heaps** are used to efficiently implement priority queues, where the root of the heap represents the highest priority element.

#### Binary Heap as Priority Queue

- A **Max-Heap** can be used for a **Max-Priority Queue**, where the largest element is dequeued first.
- A **Min-Heap** can be used for a **Min-Priority Queue**, where the smallest element is dequeued first.

---

### 4. Heap Operations

#### 1. **Heapify**

Heapify is the process of ensuring the heap property is maintained after an element is inserted or removed. This process involves comparing a node with its children and rearranging the nodes to satisfy the heap property.

For example, after inserting an element, we may need to "bubble up" or "sift up" the element to its correct position to maintain the heap property.

Similarly, after deleting the root (or extracting the maximum/minimum element), we "bubble down" or "sift down" the element to restore the heap.

**Heapify Example (Max-Heap)**:

```
              2
             / \
            3   5
           / \
          6   4
```

Heapify from the root: Since 6 > 2, we swap 6 and 2.

After swapping:
```
              6
             / \
            3   5
           / \
          2   4
```

Repeat the process for node 2 (as 2 is now in a lower position), but since 2 is already larger than both its children, the heap property is restored.

#### 2. **Insert Operation**

The insert operation involves adding a new element to the heap and then performing a **heapify-up** (or **bubble-up**) to maintain the heap property.

**Example**: Inserting `7` into a Max-Heap:

```
              10
             /  \
            7    5
           / \
          2   3
```

After inserting `7`:

```
              10
             /  \
            7    5
           / \  / \
          2  3 7
```

We then check if the newly inserted element (7) needs to be swapped with its parent (5). Since 7 is larger than 5, we swap them:

```
              10
             /  \
            7    7
           / \
          2   3
```

#### 3. **Extract Max/Min Operation**

The extract max (or min) operation removes the root of the heap, which is the largest (or smallest) element. After extraction, we move the last element to the root and heapify down to restore the heap property.

For example, extracting the maximum value from the max-heap:

Before extraction:

```
              10
             /  \
            7    5
           / \  / \
          2  3 4   1
```

Extract `10`. Move `1` to the root, then perform heapify-down:

```
              1
             /  \
            7    5
           / \  / \
          2  3 4   10
```

After heapifying:

```
              7
             /  \
            3    5
           / \  / \
          2  1 4   10
```

---

### 5. Advanced Topics

#### D-ary Heap

A **D-ary heap** is a generalization of the binary heap where each node can have `D` children instead of just two. This can be useful for specific applications where the branching factor can be adjusted for performance.

#### Fibonacci Heap

A **Fibonacci heap** is a more advanced type of heap with better amortized time complexity for some operations, such as decrease-key and delete-min operations. It's widely used in graph algorithms like Dijkstra's algorithm for finding shortest paths.

---

### 6. Use Cases and Applications of Heaps and Priority Queues

- **Dijkstra’s Algorithm**: In this shortest-path algorithm, a priority queue (min-heap) is used to always extract the node with the smallest tentative distance.
- **Huffman Coding**: Used in data compression algorithms, where the heap helps to build an optimal encoding tree.
- **Job Scheduling**: In operating systems, jobs with higher priority can be scheduled first using a priority queue.
- **K-way Merge**: When merging multiple sorted lists, a min-heap (priority queue) can be used to efficiently get the smallest element across all lists.

---

### 7. Time Complexity of Heap Operations

| Operation           | Time Complexity |
|---------------------|-----------------|
| Insert              | O(log n)        |
| Extract Max/Min     | O(log n)        |
| Heapify             | O(log n)        |
| Building a Heap     | O(n)            |

**Explanation**:
- **Insert**: After adding an element, we may need to "heapify up", which takes logarithmic time (`O(log n)`).
- **Extract Max/Min**: After removing the root, we need to "heapify down", which also takes `O(log n)` time.
- **Heapify**: Ensures the heap property is maintained, and takes logarithmic time relative to the height of the heap.
- **Building a Heap**: If we need to build a heap from an unsorted array, we can do it in linear time (`O(n)`) using a bottom-up approach.