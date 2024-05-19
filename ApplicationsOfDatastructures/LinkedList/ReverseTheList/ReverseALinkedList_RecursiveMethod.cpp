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
    Node *reverse(Node *head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        Node *restOfTheList = reverse(head->next);
        head->next->next = head;

        head->next = nullptr;

        return restOfTheList;
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
};

int main()
{
    LinkedList L;
    L.push(20);
    L.push(12);
    L.push(5);
    L.push(45);

    std::cout << "Given linked list: \n";
    L.print();

    L.head = L.reverse(L.head);

    std::cout << "Reveresed linked list: \n";
    L.print();

    return 0;
}