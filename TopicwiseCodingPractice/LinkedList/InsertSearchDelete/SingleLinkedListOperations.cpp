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

        void deleteTheGivenData(const std::string& data) {
            if(head == nullptr) {
                std::cout << "List Empty, " << data << "Not found!\n";
                return;
            }
            else {
                Node* curr = head;
                Node* prev = nullptr;
                while(curr != nullptr) {
                    if(curr->data == data) {
                        if(prev == nullptr) { // If the node to be deleted is the head
                            head = curr->next;
                        }
                        else {
                            prev->next = curr->next;
                        }
                        delete curr;
                        return;
                    }
                    prev = curr;
                    curr = curr->next;
                }
                std::cout << data << " Not found in the list\n";
            }
        }
        void deleteTheLastNode() {
            if(head == nullptr) {
                std::cout << "List Empty. Nothing to delete!\n";
                return;
            }
            // If the list contains only one node
            if(head->next == nullptr) {
                delete head;
                head = nullptr;
                return;
            }

            Node* curr = head;
            Node* prev = nullptr;
            while(curr->next){
                prev = curr;
                curr = curr->next;
            }
            // Update the next pointer of the second-to-last node to nullptr
            prev->next = nullptr;
            delete curr;
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
   std::cout << " Operations on a Single Linked List....\n";
   bool shouldExit = false;
   while(!shouldExit) {
        std::cout << "\n1. At beginning\n2. At Position\n3. At end\n4. Display\n5. Delete the Given Data\n6. Delete the last node\n7. Exit\n";
        std::cout << "Enter your option: ";
        std::string data;
        int choice;
        std::cin >> choice;
        std::string input;
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
                std::cout << "\nEnter the data to be deleted: ";
                std::getline(std::cin, input);
                sll.deleteTheGivenData(input);
                break;
            case 6 :
                sll.deleteTheLastNode();
                break;
            case 7 :
                std::cout << "\nCurrent List Items: \n";
                sll.displayList();
                std::cout << "Exiting...\n";
                shouldExit = true;
                break;
            default :
                std::cout << "Invalid option. Try again!!\n";
                break;
        }
   }
   return 0;
}