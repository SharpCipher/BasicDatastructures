#include <iostream>

const int MAX_SIZE = 100; // Maximum size of the queue

class LinearQueue {
private:
    int front;
    int rear;
    std::string queue[MAX_SIZE];

public:
    LinearQueue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(const std::string& data) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        queue[rear] = data;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    std::string peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty. No element to peek.\n";
            return "";
        }
        return queue[front];
    }

    void displayQueue() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }

        int i = front;
        while (i != rear) {
            std::cout << queue[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        std::cout << queue[rear] << std::endl;
    }
};

int main() {
    LinearQueue queue;
    queue.enqueue("data1");
    queue.enqueue("data2");
    queue.enqueue("data3");

    std::cout << "Queue after enqueue: ";
    queue.displayQueue();

    queue.dequeue();
    std::cout << "Queue after dequeue: ";
    queue.displayQueue();

    std::cout << "Peeked element: " << queue.peek() << std::endl;

    return 0;
}