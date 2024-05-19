#include <iostream>

struct QNode{
    std::string data;
    QNode* next;
    QNode(const std::string& data) : data(data), next(nullptr) {};
};

class LinearQueue {
    private:
        QNode* front;
        QNode* rear;
    public:
        LinearQueue() : front(nullptr), rear(nullptr) {};

        void enqueue(const std::string& data) {
            QNode* newNode = new QNode(data);

            // If Queue is empty, newNode is both front and rear
            if(rear == nullptr) {
                front = rear = newNode;
                newNode->next = nullptr;
            }

            // Add the newNode at the end of the queue, change the rear
            rear->next = newNode;
            rear = newNode;
        }

        void dequeueData() {
            if(front == nullptr){
                std::cout << "Queue Empty!\n";
                return;
            }

            // Store the node to be deleted which is front node and move front one node ahead
            QNode* temp = front;
            front = front->next;

            // If front becomes null, change rear also null
            if(front == nullptr) {
                rear = nullptr;
            }

            delete temp;
        }

        void displayQueue() {
            QNode* curr = front;
            while(curr != nullptr) {
                std::cout << curr->data << " ";
                curr = curr->next;
            }
            std::cout << '\n';
        }
};

int main()
{
    LinearQueue lq;
    lq.enqueue("data1");
    lq.enqueue("data2");
    lq.enqueue("data3");
    lq.displayQueue();
    lq.dequeueData();
    lq.displayQueue();
    lq.dequeueData();
    lq.displayQueue();
    lq.enqueue("AAA");
    lq.displayQueue();
    lq.enqueue("BBB");
    lq.displayQueue();
    
    return 0;
}