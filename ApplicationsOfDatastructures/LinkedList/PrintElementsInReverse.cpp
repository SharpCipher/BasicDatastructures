/*
Given a Linked List, print it in reverse direction using recursion.
Note: Do not reverse the list.
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

void printLinkedListReverse(struct Node* head) {
    if(head == nullptr) {
        return;
    }
    printLinkedListReverse(head->next);
    std::cout << head->data << " ";
}

int main() {
    int n,value;
    std::cin >> n;
    for(int i=0; i<n; ++i) {
        std::cin >> value;
        createList(value);
    }
    displayList();
    std::cout << "List of elements in Reverse order: \n";
    printLinkedListReverse(head);
    std::cout << '\n';
    return 0;
}