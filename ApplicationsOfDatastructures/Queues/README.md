# Queue Data Structure

## Table of Contents
1. [Introduction](#introduction)
2. [Queue Operations](#queue-operations)
   - [Enqueue (Insertion)](#enqueue-insertion)
   - [Dequeue (Removal)](#dequeue-removal)
   - [Peek/Front (Get First Element)](#peek-front-get-first-element)
   - [IsEmpty (Check if Empty)](#isempty-check-if-empty)
   - [IsFull (Check if Full)](#isfull-check-if-full)
3. [Types of Queues](#types-of-queues)
   - [Simple Queue (FIFO)](#simple-queue-fifo)
   - [Circular Queue](#circular-queue)
   - [Priority Queue](#priority-queue)
   - [Deque (Double-Ended Queue)](#deque-double-ended-queue)
4. [Queue Implementation](#queue-implementation)
   - [Array-based Queue](#array-based-queue)
   - [Linked List-based Queue](#linked-list-based-queue)
5. [Applications of Queues](#applications-of-queues)
6. [Advanced Topics](#advanced-topics)
   - [Circular Queue Implementation](#circular-queue-implementation)
   - [Priority Queue Implementation](#priority-queue-implementation)
   - [Deque Implementation](#deque-implementation)
   - [Queue in Multi-threaded Environments](#queue-in-multi-threaded-environments)

---

## Introduction

A **Queue** is a linear data structure that follows the **First-In-First-Out (FIFO)** principle. This means that the element added first will be the one removed first, similar to a line at a ticket counter.

In a queue, elements are added from the **rear** and removed from the **front**. Queues are widely used in various real-world applications, including scheduling tasks, managing resources, and simulating real-world queues.

## Queue Operations

### Enqueue (Insertion)
- **Definition**: Adds an element to the rear of the queue.
- **Time Complexity**: O(1) in an array-based queue (if not full) or linked list-based queue.

```cpp
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full!";
    } else {
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
    }
}
```

### Dequeue (Removal)
- **Definition**: Removes and returns the element from the front of the queue.
- **Time Complexity**: O(1)

```cpp
int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!";
        return -1;
    } else {
        int value = arr[front];
        front = (front + 1) % MAX_SIZE;
        return value;
    }
}
```

### Peek/Front (Get First Element)
- **Definition**: Returns the element at the front of the queue without removing it.
- **Time Complexity**: O(1)

```cpp
int peek() {
    if (isEmpty()) {
        cout << "Queue is empty!";
        return -1;
    }
    return arr[front];
}
```

### IsEmpty (Check if Empty)
- **Definition**: Checks if the queue is empty.
- **Time Complexity**: O(1)

```cpp
bool isEmpty() {
    return front == rear;
}
```

### IsFull (Check if Full)
- **Definition**: Checks if the queue is full.
- **Time Complexity**: O(1)

```cpp
bool isFull() {
    return (rear + 1) % MAX_SIZE == front;
}
```

## Types of Queues

### Simple Queue (FIFO)
- **Description**: A basic queue where elements are added from the rear and removed from the front.
- **Example**: Task scheduling, customer service queues.

### Circular Queue
- **Description**: A queue that wraps around when the end of the queue is reached. Useful for saving space when using array-based implementations.
- **Example**: Buffer in streaming data.

### Priority Queue
- **Description**: A queue where each element has a priority associated with it, and elements are dequeued based on priority (not necessarily FIFO).
- **Example**: CPU task scheduling, Dijkstra's shortest path algorithm.

### Deque (Double-Ended Queue)
- **Description**: A queue where elements can be added or removed from both the front and rear.
- **Example**: Undo operations in text editors, deque-based sliding window problems.

## Queue Implementation

### Array-based Queue
- **Pros**: Simple to implement.
- **Cons**: Fixed size, potential space wastage if not using circular implementation.

### Linked List-based Queue
- **Pros**: Dynamic size.
- **Cons**: Slightly more complex to implement, requires extra space for pointers.

## Applications of Queues

1. **CPU Scheduling**: Processes are handled in a queue structure.
2. **Breadth-First Search (BFS)**: Used to explore nodes layer by layer in graph algorithms.
3. **Caching**: FIFO queues are used in page replacement algorithms (e.g., LRU cache).
4. **I/O Buffering**: Queues manage input/output requests in operating systems.

## Advanced Topics

### Circular Queue Implementation
A **circular queue** wraps around when the end of the array is reached, utilizing available space more efficiently.

```cpp
int front = 0, rear = 0;

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full!";
    } else {
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
    }
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!";
    } else {
        front = (front + 1) % MAX_SIZE;
    }
}
```

### Priority Queue Implementation
A **priority queue** allows elements to be dequeued based on priority. Implemented using arrays or binary heaps for efficiency.

```cpp
struct Node {
    int data;
    int priority;
};

void enqueue(int data, int priority) {
    // Add node in sorted order based on priority
}

int dequeue() {
    // Remove node with highest priority
}
```

### Deque Implementation
A **deque** is implemented using doubly linked lists or arrays with circular behavior.

```cpp
class Deque {
public:
    void insertFront(int value);
    void insertRear(int value);
    void deleteFront();
    void deleteRear();
};
```

### Queue in Multi-threaded Environments
In multi-threaded environments, queues often serve as **message-passing structures**. They require synchronization mechanisms such as **mutexes** or **semaphores** to avoid race conditions.

```cpp
std::queue<int> q;
std::mutex mtx;

void producer() {
    std::lock_guard<std::mutex> lock(mtx);
    q.push(1);
}

void consumer() {
    std::lock_guard<std::mutex> lock(mtx);
    q.pop();
}
```
