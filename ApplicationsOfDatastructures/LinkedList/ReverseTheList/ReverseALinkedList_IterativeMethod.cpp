#include <iostream>
struct Node {
    int data;
    struct Node *next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

struct LinkedList {
    Node *head;
    LinkedList() {
        head = nullptr;
    }
    
    // Function to Reverse the linked list
    void reverse() {
        // Initialize prev, curr, and next pointers
        Node *curr = head;
        Node *prev = nullptr, *next = nullptr;
        while(curr != nullptr) {
            next = curr->next; // store next
            curr->next = prev; // Reverse current node's pointer
            // Move pointers to one position ahead
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // Function to print the linked list
    void print() {
        struct Node *temp = head;
        while(temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << '\n';
    }

    void push(int data) {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main()
{
    LinkedList L;  // Empty list
    L.push(20);
    L.push(12);
    L.push(5);
    L.push(45);
    
    std::cout << "Given Linked list: \n";
    L.print();

    L.reverse();

    std::cout << "Reversed linked list: \n";
    L.print();

    return 0;
}