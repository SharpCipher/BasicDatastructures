#include <iostream>

struct Node {
    std::string data;
    struct Node* next;

    Node(std::string data) {
        this->data = data;
        this->next = nullptr;
    }
};
struct Node* head = nullptr;

void insertAtBeg(Node*& head, std::string data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtPos(Node*& head, std::string data, int pos) {

}

void insertAtEnd(Node*& head, std::string data) {

}

void displayList(Node* head) {
    Node* temp = head;
    while(temp != nullptr){
        std::cout << temp->data << "--->";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

int main()
{
   std::cout << "Insertion into a Single Linked List....\n";
   while(1) {
        std::cout << "\n1. At beginning\n2. At Position\n3. At end\n4. Display\n5. Exit\n";
        std::cout << "Enter your option: ";
        int choice;
        std::cin >> choice;
        std::string data;
        if(choice == 5){
            std::cout << "Current linked list items: \n";
            displayList(head);
            break;
        }

        switch(choice) {
            case 1 :
                std::cout << "Enter the data: ";
                std::cin >> data;
                insertAtBeg(head, data);
                break;
            case 2 :
                std::cout << "Enter the data: ";
                std::cin >> data;
                int pos;
                std::cout << "Enter the position: ";
                std::cin >> pos;
                insertAtPos(head, data, pos);
                break;
            case 3 :
                std::cout << "Enter the data: ";
                std::cin >> data;
                insertAtEnd(head, data);
                break;
            case 4 :
                std::cout << "The list items: \n";
                displayList(head);
                break;
        }
   }
    
   return 0;
}