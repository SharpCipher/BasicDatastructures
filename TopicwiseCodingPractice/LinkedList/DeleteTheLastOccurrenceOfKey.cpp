/*
Given a linked list and a key(data) to be deleted. Delete last occurrence of key(data) from linked.
The list may have duplicates.

Example:

Input:   1->2->3->5->2->10, key = 2
Output:  1->2->3->5->10
*/

#include <iostream>

struct Node{
    int data;
    struct Node* next;
    Node(const int& data) : data(data), next(nullptr) {};
};

class SingleLinkedList {
    private:
        struct Node* head;
    public:
        SingleLinkedList() {
            head = nullptr;
        }
        void print() {
            struct Node* temp = head;
            while(temp != nullptr) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << '\n';
        }

        void push(const int& data) {
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }

        void deleteTheLastOccurrenceOfData(const int& key) {
            Node* ptr = nullptr;

            // Start from the head and find the node to be deleted
            Node* curr = head;
            while(curr) {
                if(curr->data == key){  // Found the key, update ptr
                    ptr = curr;
                }
                curr = curr->next;
            }

            // Key occurs at least once and it's the last node
            if(ptr != nullptr && ptr->next == nullptr) {
                curr = head;
                while(curr->next != ptr) {
                    curr = curr->next;
                }
                curr->next = nullptr;
            }

            // Key occurs at least once and it's not the last node
            if(ptr != nullptr && ptr->next != nullptr) {
                ptr->data = ptr->next->data;
                curr = ptr->next;
                ptr->next = ptr->next->next;
                delete curr;
            }

        }
};

int main()
{
    SingleLinkedList sll;
    sll.push(20);
    sll.push(70);
    sll.push(50);
    sll.push(10);
    sll.push(10);
    sll.push(70);

    sll.print();

    sll.deleteTheLastOccurrenceOfData(70);

    sll.print();

    return 0;
}