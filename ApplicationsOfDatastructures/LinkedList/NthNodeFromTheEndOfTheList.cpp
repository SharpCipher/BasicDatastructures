/*
The idea is to maintain two pointers, say ptr1 and ptr2 point to the head of Linked List and move ptr2 to the Nth node from
the head to ensure that the distance between ptr1 and ptr2 is (N – 1).
Now, move both the pointers simultaneously until ptr2 reaches the last node. Since the distance between
ptr1 and ptr2 is (N – 1), so when ptr2 will reach the last node, ptr1 will reach Nth node from
the end of Linked List. Return the value of node pointed by ptr1.
*/

#include <iostream>

struct Node {
    int data;
    struct Node *next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class SingleLinkedList {
    private:
        Node* head;
    public:
        SingleLinkedList() {
            head = nullptr;
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

    void nthNodeFromEndOfTheList(const int& n) {
        Node* ptr1 = head;
        Node* ptr2 = head;
        if(head == nullptr) {
            std::cout << "list empty!!\n";
            return;
        }

        // Move ptr2 to the nth node from the beginning
        for(int i=1; i<n; ++i) {
            ptr2 = ptr2->next;
            if(ptr2 == nullptr) {
                std::cout << n << "is greater than the no.of nodes in the list!\n";
                return;
            }
        }

        // Move ptr2 and ptr1 by one node until ptr2 reaches the end of the list
        while(ptr2 != nullptr  && ptr2->next != nullptr) {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }
        std::cout << "Node number " << n << " from end is: " << ptr1->data << '\n';
    }
};

int main()
{
    SingleLinkedList sll;
    sll.push(20);
    sll.push(30);
    sll.push(50);
    sll.push(10);
    sll.push(40);
    sll.push(70);

    sll.print();

    sll.nthNodeFromEndOfTheList(3);

    return 0;
}