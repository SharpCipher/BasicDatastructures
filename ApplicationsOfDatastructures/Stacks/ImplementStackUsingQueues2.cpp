#include <iostream>
#include <queue>

class StackUsingQueues {
    private:
        std::queue<int> Q1, Q2;
        int stackSize;
    public:
        StackUsingQueues() {
            stackSize = 0;
        }
        void push(int x) {
            Q2.push(x);
            stackSize -= 1;
            while(!Q1.empty()) {
                int temp = Q1.front();
                Q1.pop();
                Q2.push(temp);
            }
            std::queue<int> temp = Q1;
            Q1 = Q2;
            Q2 = temp;
        }
        int pop() {
            if(Q1.empty()) {
                std::cout << "Stack Underflow!!\n";
                return -1;
            }
            int stackTop = Q1.front();
            Q1.pop();
            stackSize -= 1;
            return stackTop;
        }
};

int main() {

    StackUsingQueues obj;
    obj.push(5);
    obj.push(6);
    obj.push(2);
    std::cout << obj.pop() << " ";
    std::cout << obj.pop() << " ";
    std::cout << obj.pop() << " ";
    std::cout << std::endl;
    return 0;
}