/*
Given a Linked List, find the element at the kth position.
List: 1→3→4→7
k: 2
Answer: 3
*/

#include <iostream>

struct Node {
    public:
        int data;
        struct Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};
struct Node *head = nullptr;
void displayList() {
    if(head == nullptr) {
        std::cout << "List is empty!!\n";
        return;
    }
    std::cout << "Entered list of elements in the order: \n";
    struct Node *ptr = head;
    while(ptr != nullptr) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << '\n';
}
void createList(int val) {
        struct Node *temp;
        temp = new Node(val);
        temp->next = nullptr;
        if(head == nullptr) {
            head = temp;
        }
        else {
            struct Node* ptr = head;
            while(ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
}
void findKthElem(int pos) {
    int count = 0;
    while(head) {
        count += 1;
        if(pos == count)
            std::cout << "Element at " << pos << ": " << head->data;
        head = head->next;
    }
}
int main() {
    int n,value;
    std::cin >> n;
    for(int i=0; i<n; ++i) {
        std::cin >> value;
        createList(value);
    }
    displayList();
    std::cout << "Enter the position: ";
    int pos;
    std::cin >> pos;
    findKthElem(pos);
    std::cout << '\n';
    return 0;
}