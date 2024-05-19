#include <iostream>

// Node class to represent each element in the linked list
template <typename T>
class Node {
    public:
        T data;
        Node<T> *next;

        Node(T value) : data(value), next(nullptr) {}
};

// Stack class using a linked list
template <typename T>
class Stack {
    private:
        Node<T> *top; // Pointer to the top of the stack
    public:
        Stack() : top(nullptr) {}
    
    // Function to push new element into stack
    void push(T value) {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;        
    }

    // Function to pop the element from the stack
    void pop() {
        if(isEmpty()) {
            std::cout << "Stack Underflow!!\n";
            return;
        }
        Node<T> *temp = top;
        top = top->next;

        delete temp;
    }

    // Function to get the top element of the stack
    T peek() {
        if(isEmpty()) {
            std::cerr << "Stack Underflow!\n";
            exit(EXIT_FAILURE);
        }

        return top->data;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {

    Stack<int> integerStack;

    integerStack.push(1);
    integerStack.push(2);
    integerStack.push(3);

    std::cout << "Top element: " << integerStack.peek() << '\n';

    integerStack.pop();
    std::cout << "Top element after a pop: " << integerStack.peek() << '\n';

    return 0;
}