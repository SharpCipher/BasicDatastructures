#include <iostream>

struct Node {
    std::string data;
    struct Node* next;
    Node(std::string data) : data(data), next(nullptr) {};
};

class Stack {
    private:
        Node* head;
    public:
        Stack() : head(nullptr) {};

        ~Stack() {

        }

        void push(const std::string& data) {
            Node* newNode = new Node(data);
            if(head == nullptr) {
                newNode->next = nullptr;
                head = newNode;
                return;
            }
            else {
                newNode->next = head;
                head = newNode;
            }
        }

        std::string pop() {
            return "";
        }

        void displayStack() {
            Node* temp = head;
            while(temp) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << '\n';
        }
};

int main()
{
    Stack st;
    std::cout << "Stack Using Linked List......\n";
    bool shouldExit = false;
    while(!shouldExit) {
        std::cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        std::string data;
        std::string popped;
        int choice;
        std::cin >> choice;

        // Clear the input buffer before reading next input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice) {
            case 1 :
                std::cout << "Enter the data: ";
                std::getline(std::cin, data);
                st.push(data);
                break;
            case 2 :
                popped = st.pop();
                std::cout << "Popped " << popped << '\n';
                break;
            case 3 :
                std::cout << "Stack Elements: \n";
                st.displayStack();
                break;
            case 4 :
                std::cout << "Exiting....\n";
                shouldExit = true;
                break;
            default :
                std::cout << "Invalid choice, Try again!!\n";
                break;
        }
    } 
    return 0;
}