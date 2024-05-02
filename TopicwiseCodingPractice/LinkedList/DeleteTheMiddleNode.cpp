/*
Given a singly linked list, delete the middle of the linked list. For example,
if the given linked list is 1->2->3->4->5 then the linked list should be modified to 1->2->4->5

If there are even nodes, then there would be two middle nodes, we need to delete
the second middle element. For example, if given linked list is 1->2->3->4->5->6 then
it should be modified to 1->2->3->5->6.
If the input linked list is NULL, then it should remain NULL.
If the input linked list has 1 node, then this node should be deleted and a new head should
be returned. 

*/
#include <iostream>

struct Node {
    int data;
    struct Node* next;

    Node(const int& data) : data(data), next(nullptr){};
};

class SingleLinkedList{
    private:
        Node* head;
    public:
        SingleLinkedList() {
            head = nullptr;
        }
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

    void deleteTheMiddleNode() {
        if(head == nullptr) {
            return;
        }
        if(head->next == nullptr) {
            delete head;
            return;
        }
        Node* ptr1 = head;
        Node* ptr2 = head;

        Node* prev = nullptr;

        while(ptr2 != nullptr && ptr2->next != nullptr) {
            ptr2 = ptr2->next->next;
            prev = ptr1;
            ptr1 = ptr1->next;
        }

        prev->next = ptr1->next;
        delete ptr1;
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
    sll.push(80);

    sll.print();

    sll.deleteTheMiddleNode();

    sll.print();

    return 0;
}