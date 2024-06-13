#include <iostream>

class Stack {
    int* data;
    int top;
    int capacity;

    public:
        Stack(int size) : capacity(size), top(-1) {
            data = new int[size];
        }
        ~Stack() {
            delete[] data;
        }

        void push(int value) {
            if(top == capacity - 1) {
                throw std::overflow_error("Stack Overflow!\n");
            }
            data[++top] = value;
        }

        int pop() {
            if(top == -1) {
                throw std::underflow_error("Stack Underflow!\n");
            }
            return data[top--];
        }

        int peek() {
            if(top == -1) {
                throw std::underflow_error("Stack Underflow!\n");
            }
            return data[top];
        }

        bool isEmpty() const {
            return top == -1;
        }

        int size() const {
            return top+1;
        }
};

int main()
{
    Stack stack(5);
    stack.push(12);
    stack.push(22);
    stack.push(32);

    std::cout << "Top element: " << stack.peek() << '\n';
    std::cout << "Stack size: " << stack.size() << '\n';

    while(!stack.isEmpty()) {
        std::cout << stack.pop() << " ";
    }
    std::cout << '\n';

    return 0;
}