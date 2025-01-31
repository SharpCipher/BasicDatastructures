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
            // If the pos exceeds the size of the list
            if(pos > c){
                std::cout << "Invalid position!!\n";
                return;
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
            int deletionCount = 0;
            if(head == nullptr) {
                std::cout << "List Empty, " << data << "Not found!\n";
                return;
            }
                Node* curr = head;
                Node* prev = nullptr;
                while(curr != nullptr) {
                    if(curr->data == data) {
                        if(prev == nullptr) { // If the node to be deleted is the head
                            head = curr->next;
                            delete curr;
                            curr = head;
                        }
                        else {
                            prev->next = curr->next;
                            delete curr;
                            curr = prev->next;
                        }
                        deletionCount++;
                    }
                    else {
                        prev = curr;
                        curr = curr->next;
                    }
                }
                if(deletionCount > 0) {
                    std::cout << deletionCount << " instances of " << data << " deleted from the list\n";
                }
                else {
                    std::cout << data << " not found in the list!!\n";
                }
        }

        void deleteTheFirstNode() {
            if(head == nullptr) {
                std::cout << "List Empty. Nothing to delete!\n";
                return;
            }
            Node* temp = head;
            head = head->next;
            delete temp;
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
        void searchData(const std::string& searchString) {
            if(head == nullptr) {
                std::cout << "Empty list. " << searchString << " Not found!\n";
                return;
            }
            int pos = 1;
            Node* temp = head;
            while(temp) {
                if(temp->data == searchString) {
                    std::cout << searchString << " found at position " << pos << '\n';
                    return;
                }
                temp = temp->next;
                pos++;
            }
            std::cout << searchString << " Not found!!\n";
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
        std::cout << "\n1. Insert At beginning\n2. Insert At Position\n3. Insert At end\n";
        std::cout << "4. Display the list\n5. Delete the Given Data\n6. Delete the first node\n";
        std::cout << "7. Delete the last node\n8. Search data\n9. Exit\n";
        std::cout << "Enter your option: ";
        std::string data;
        int choice;
        std::cin >> choice;
        std::string input;
        std::string searchString;
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
                sll.deleteTheFirstNode();
                break;
            case 7 :
                sll.deleteTheLastNode();
                break;
            case 8 :
                std::cout << "Enter the data to be searched: ";
                std::getline(std::cin, searchString);
                sll.searchData(searchString);
                break;
            case 9 :
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