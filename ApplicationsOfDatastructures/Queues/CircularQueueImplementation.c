#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Maximum size of the circular queue

// Structure definition for the circular queue
typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} CircularQueue;

// Function to create an empty circular queue
CircularQueue* createCircularQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->front = -1; // Initialize front and rear
    queue->rear = -1;
    return queue;
}

// Function to check if the circular queue is full
int isFull(CircularQueue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to check if the circular queue is empty
int isEmpty(CircularQueue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to add an element to the circular queue
void enqueue(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Circular queue is full, cannot enqueue.\n");
        return;
    }
    if (isEmpty(queue)) { // If queue is empty, set front and rear to 0
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE; // Circular increment
    }
    queue->items[queue->rear] = value;
}

// Function to remove an element from the circular queue
int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty, cannot dequeue.\n");
        return -1;
    }
    int removedItem = queue->items[queue->front];
    if (queue->front == queue->rear) { // If only one element is present
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE; // Circular increment
    }
    return removedItem;
}

// Function to peek at the front element of the circular queue
int peek(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular queue is empty, cannot peek.\n");
        return -1;
    }
    return queue->items[queue->front];
}

int main() {
    CircularQueue* queue = createCircularQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Front element: %d\n", peek(queue));

    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Front element after dequeue: %d\n", peek(queue));

    return 0;
}
