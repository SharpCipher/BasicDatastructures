#include <iostream>
#include <string>

struct Node {
    std::string data;
    struct Node* prev;
    struct Node* next;
    Node(std::string data) {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

class DoubleLinkedList {
    private:
        Node* head;

    public:
        DoubleLinkedList() {
             head = nullptr;
        }

        void push(const std::string& data) {
            struct Node* newNode = new Node(data);
            newNode->data = data;
            newNode->prev = nullptr;
            newNode->next = head;

            if(head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
        }

        void printList() {
            struct Node* temp = head;
            std::cout << "Current Double linked list: \n";
            while(temp != nullptr) {
                std::cout << temp->data << " <---> ";
                temp = temp->next;
            }
            std::cout << "\\NULL\\";
            std::cout << '\n';
        }

        void reverse() {
            struct Node* temp = nullptr;
            struct Node* curr = head;

            while(curr != nullptr) {
                temp = curr->prev;
                curr->prev = curr->next;
                curr->next = temp;
                curr = curr->prev;
            }

            if(temp != nullptr) {
                head = temp->prev;
            }
        }
};

int main()
{
    DoubleLinkedList dll;
    dll.push("reverse");
    dll.push("a double");
    dll.push("linked");
    dll.push("list");
    dll.printList();
    dll.reverse();
    dll.printList();

    return 0;
}