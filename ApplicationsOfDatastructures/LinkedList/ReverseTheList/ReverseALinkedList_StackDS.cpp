#include <iostream>
#include <stack>

struct Node {
    std::string data;
    struct Node* next;
    Node(const std::string& data) : data(data), next(nullptr) {};
};

struct SingleLinkedList {
    private:
        struct Node *head;
    public:
        SingleLinkedList() {
            head = nullptr;
        }
        void push(const std::string& data) {
            struct Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }
        void reverse() {
            if(head == nullptr)
                return;
            std::stack<Node*> st;
            Node* temp = head;
            while(temp->next != nullptr) {
                st.push(temp);
                temp = temp->next;
            }
            head = temp;
            while(!st.empty()) {
                temp->next = st.top();
                st.pop();
                temp = temp->next;
            }
            temp->next = nullptr;
        }

        void printList() {
            struct Node* temp = head;
            while(temp != nullptr) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << '\n';
        }

        ~SingleLinkedList() {
            while(head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
};

int main()
{
    SingleLinkedList sll;
    sll.push("123 |");
    sll.push("reversal |");
    sll.push("linked list |");
    sll.push("using stack to |");
    std::cout << "Before Reversal: \n";
    sll.printList();
    std::cout << "After reversal: \n";
    sll.reverse();
    sll.printList();

    return 0;
}