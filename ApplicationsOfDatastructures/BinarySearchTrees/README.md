# Binary Search Trees (BST) 📚

A **Binary Search Tree (BST)** is a data structure that stores elements in a hierarchical structure, allowing for fast and efficient searching, insertion, and deletion of values. Each node in a BST follows a unique ordering rule, which makes it an ideal choice for applications requiring dynamic ordering and fast lookups.

## Table of Contents
- [Introduction](#introduction)
- [Properties of a BST](#properties-of-a-bst)
- [Advantages and Limitations](#advantages-and-limitations)
- [Operations on BST](#operations-on-bst)
  - [Insertion](#insertion)
  - [Deletion](#deletion)
  - [Searching](#searching)
- [Tree Traversals](#tree-traversals)
- [Examples](#examples)
- [Applications](#applications)

---

## Introduction

A **Binary Search Tree (BST)** is a type of binary tree where:
- The **left child** of a node contains only values **less than** the node's value.
- The **right child** of a node contains only values **greater than** the node's value.

This ordering allows **binary search**, making BSTs highly efficient for **searching, insertion, and deletion** operations when the tree is balanced.

### Diagram of a Binary Search Tree (BST)

Example BST:

```
       8
      / \
     3   10
    / \    \
   1   6    14
      / \   /
     4   7 13
```

---

## Properties of a BST

1. **Binary Tree Structure**: Each node has at most two children.
2. **Value Ordering**:
   - For any given node, all nodes in the left subtree contain values **less than** the node’s value.
   - All nodes in the right subtree contain values **greater than** the node’s value.
3. **Recursive Structure**: Each subtree of a BST is also a BST.
4. **Unique Paths**: There is a single unique path from the root to any node in the tree, which allows for efficient searching.
5. **Balanced vs. Unbalanced BST**:
   - In a **balanced BST**, the height (maximum depth) is kept close to the minimum possible height, ensuring efficient operations.
   - In an **unbalanced BST**, the height can grow as large as the number of nodes (e.g., a linked list), reducing efficiency.

---

## Advantages and Limitations

### Advantages
- **Efficient Searching**: BSTs offer \(O(\log n)\) search, insert, and delete operations on average if balanced.
- **Dynamic Ordering**: BSTs naturally maintain sorted data without requiring reordering operations.

### Limitations
- **Unbalanced Trees**: An unbalanced BST may degrade to \(O(n)\) time complexity for all operations.
- **Space Overhead**: Each node requires additional memory for pointers to its children.
  
To address these limitations, **self-balancing trees** like **AVL trees** or **Red-Black trees** are often used, ensuring a balance factor for efficient operation.

---

## Operations on BST

### 1. Insertion

The **insertion** operation adds a new value to the BST:
- Start at the root and compare the value to insert with the current node.
- If the value is smaller, move to the left child; if larger, move to the right.
- Continue down the tree until an empty spot is found and insert the new node there.

#### Insertion Example

Insert `5` into this tree:

```
      10
     /
    3
     \
      8
```

After inserting `5`:

```
      10
     /
    3
     \
      8
     /
    5
```

### 2. Deletion

**Deletion** in a BST must handle three cases:
- **Node has no children (Leaf node)**: Simply remove the node.
- **Node has one child**: Remove the node and replace it with its child.
- **Node has two children**: Replace the node with its **in-order successor** (the smallest node in its right subtree) or its **in-order predecessor** (the largest node in its left subtree), then delete the successor.

#### Deletion Example

Delete `10` from the following BST:

```
      10
     /  \
    5    15
```

After deleting `10`:

```
      15
     /
    5
```

### 3. Searching

The **search** operation leverages the ordering property of BSTs:
- Start at the root.
- If the value is smaller, search the left subtree; if larger, search the right subtree.
- Repeat until finding the value or reaching a `nullptr`.

#### Searching Example

Search for `7` in this tree:

```
       10
      /  \
     5    15
    / \
   2   7
```

Steps:
1. Compare `7` with `10`: Move left.
2. Compare `7` with `5`: Move right.
3. Find `7`.

---

## Tree Traversals

Tree traversals are methods for visiting all nodes in a BST. The traversal order determines how we visit each node.

### 1. In-Order Traversal (Left, Root, Right)
   - Visits nodes in ascending order for a BST.
   - **Example**: `1 3 4 6 7 8 10 13 14`

### 2. Pre-Order Traversal (Root, Left, Right)
   - Visits the root node first, followed by the left and right subtrees.
   - **Example**: `8 3 1 6 4 7 10 14 13`

### 3. Post-Order Traversal (Left, Right, Root)
   - Visits all children before visiting the root.
   - **Example**: `1 4 7 6 3 13 14 10 8`

### 4. Level-Order Traversal (Breadth-First)
   - Visits nodes level by level from top to bottom.
   - **Example**: `8 3 10 1 6 14 4 7 13`

---

## Examples

### Insertion Example

1. **Insert** `5, 3, 7, 1, 4` into an empty BST:

   ```
        5
       / \
      3   7
     / \
    1   4
   ```

### Deletion Example

2. **Delete** `3` from the BST:

   ```
        5
       / \
      4   7
     /
    1
   ```

### Search Example

3. **Search for** `4`:
   - Traverse `5 -> 3 -> 4`, and find `4`.

---

## Applications

1. **Databases and File Systems**: BSTs allow for efficient retrieval, insertion, and deletion operations.
2. **Network Routing**: BSTs help organize routing paths for efficient lookups.
3. **Expression Parsing**: In compilers, BSTs represent arithmetic expressions for parsing.
4. **In-Memory Storage for Dictionaries**: Used in spell-checking software and autocomplete features.
5. **Data Compression Algorithms**: BSTs are used in Huffman coding and other compression techniques.
