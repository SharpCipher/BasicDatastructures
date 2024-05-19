#include <iostream>
#include <queue>

class StackUsingQueues {
    private:
        std::queue<int> Q;
        int stackSize;
    public:
        StackUsingQueues() {
            stackSize = 0;
        }
        void push(int x) {
            Q.push(x);

            for(int i=0; i<stackSize; ++i) {
                int temp = Q.front();
                Q.pop();
                Q.push(temp);
            }
            stackSize++;
        }
        
        int pop() {
            if(Q.empty()) {
                std::cout << "Stack Underflow!\n";
                return -1;
            }
            int stackTop = Q.front();
            Q.pop();
            stackSize -= 1;
            return stackTop;
        }
};

int main() {
    StackUsingQueues obj;
    obj.push(5);
    obj.push(6);
    obj.push(1);
    obj.push(2);
    obj.push(3);
    std::cout << obj.pop() << " ";
    std::cout << obj.pop() << " ";
    std::cout << obj.pop() << " ";
    std::cout << obj.pop() << " ";
    std::cout << std::endl;
    return 0;
}