#include <iostream>
#include <queue>

class StackUsingQueues {
    public:
        StackUsingQueues() {
            stackSize = 0;
        }
        void push(int x) {
            Q1.push(x);
            stackSize += 1;
        }
        int pop() {
            if(Q1.empty()) {
                std::cout << "Stack Underflow! \n";
                return INT_MIN;
            }
            while(Q1.size() != 1){
                int temp = Q1.front();
                Q1.pop();
                Q2.push(temp);
            }
            int stackTop = Q1.front();
            Q1.pop();
            stackSize -= 1;
            std::swap(Q1, Q2);

            return stackTop;
        }
    private:
        std::queue<int> Q1, Q2;
        int stackSize;
};

int main() {
    StackUsingQueues obj;
    obj.push(5);
    obj.push(6);
    std::cout << obj.pop() << '\n';
    return 0;
}