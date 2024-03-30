#include <iostream>

struct Node {
    std::string data;
    struct Node* next;

    Node(std::string data) : data(data), next(nullptr) {}
};

class SingleLinkedList {
    private:
        Node *head;
    public:
        SingleLinkedList() : head(nullptr) {};

        ~SingleLinkedList() {
            Node* current = head;
            while(current) {
                Node* next = current->next;
                delete current;
                current = next;
            }
            head = nullptr;
        }

        void insertAtBeg(const std::string& data) {
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }

        void insertAtPos(const std::string& data, int pos) {
            Node* newNode = new Node(data);
            Node* temp = head;
            Node* prev = nullptr;

            int c = 1;

            while(temp) {
                if(c == pos){
                    newNode->next = temp;
                    if(prev)
                        prev->next = newNode;
                    else
                        head = newNode;

                    return;
                }
                prev = temp;
                temp = temp->next;
                c++;
            }
            // If the pos exceeds the size of the list, insert at the end
            if(pos == c){
                if(prev)
                    prev->next = newNode;
                else
                    head = newNode;
            }
        }

        void insertAtEnd(const std::string& data) {
            Node* newNode = new Node(data);
            if(head == nullptr) {
                head = newNode;
                return;
            }
            Node* temp = head;
            while(temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = nullptr;
        }

        void displayList() {
            Node* temp = head;
            while(temp){
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << '\n';
        }
};

int main()
{
   SingleLinkedList sll;
   std::cout << "Insertion into a Single Linked List....\n";
   while(1) {
        std::cout << "\n1. At beginning\n2. At Position\n3. At end\n4. Display\n5. Exit\n";
        std::cout << "Enter your option: ";
        std::string data;
        int choice;
        std::cin >> choice;

        // Clear the input buffer before reading next input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice) {
            case 1 :
                std::cout << "Enter the data: ";
                std::getline(std::cin, data);
                sll.insertAtBeg(data);
                break;
            case 2 :
                std::cout << "Enter the data: ";
                std::getline(std::cin, data);
                int pos;
                std::cout << "Enter the position: ";
                std::cin >> pos;
                sll.insertAtPos(data, pos);
                break;
            case 3 :
                std::cout << "Enter the data: ";
                std::getline(std::cin, data);
                sll.insertAtEnd(data);
                break;
            case 4 :
                std::cout << "\nThe list items: \n";
                sll.displayList();
                break;
            case 5 :
                std::cout << "\nCurrent List Items: \n";
                sll.displayList();
                std::cout << "Exiting...\n";
                return 0;
            default :
                std::cout << "Invalid option. Try again!!\n";
        }
   }
    
   return 0;
}