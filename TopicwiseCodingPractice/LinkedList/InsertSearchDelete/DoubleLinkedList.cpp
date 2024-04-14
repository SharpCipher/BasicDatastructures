#include <iostream>
struct Node{
    std::string data;
    struct Node* prev;
    struct Node* next;
    Node(std::string data) : data(data), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList {
    private:
        Node* head;
    public:
        DoubleLinkedList() : head(nullptr) {};

        ~DoubleLinkedList() {
            Node* curr = head;
            while(curr) {
                Node* next = curr->next;
                delete curr;
                curr = next;
            }
            head = nullptr;
        }

        void insertAtBeg(const std::string& data) {
            Node* newNode = new Node(data);
            newNode->prev = nullptr;
            newNode->next = head;
            head = newNode;
        }

        void insertAtPos(const std::string& data, int pos) {
            Node* newNode = new Node(data);
            int c = 1;
            Node* temp = head;
            
            // Handle insertion at the beginning or empty list
            if(pos == 1 || !head) {
                newNode->next = head;
                if(head) head->prev = newNode;
                head = newNode;
                return;
            }

            // Traverse the list to find the insertion point
            while(temp && c < pos - 1) {
                temp = temp->next;
                c++;
            }

            // Handle invalid position
            if(!temp) {
                std::cout << "Invalid position!!\n";
                return;
            }

            // Insert the node at the desired position
            newNode->next = temp->next;
            newNode->prev = temp;
            if(temp->next) 
                temp->next->prev = newNode;
            temp->next = newNode;
        }

        void insertAtEnd(const std::string& data) {
            Node* newNode = new Node(data);
            newNode->next = nullptr;
            // If the list is empty, make the new node the head
            if(head == nullptr) {
                head = newNode;
                newNode->prev = nullptr;
                return;
            }

            Node* temp = head;
            while(temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }

        void deleteTheFirstNode() {
            if(head == nullptr) {
                std::cout << "List is empty, Can't delete!!\n";
                return;
            }
            Node* temp = head;
            head = head->next;
            delete(temp);
            if(head != nullptr)
                head->prev = nullptr;
        }

        void deleteTheGivenData(const std::string& data) {
            if(head == nullptr) {
                std::cout << "List is empty, Can't delete!!\n";
                return;
            }
            Node* temp = head;
            int deletionCount = 0;
            while(temp) {
                if(temp->data == data) {
                    if(temp == head) {
                        head = temp->next;
                        if(head != nullptr) {
                            head->prev = nullptr;
                        }
                        delete temp;
                        temp = head;
                        deletionCount++;
                    }
                    else {
                        temp->prev->next = temp->next;
                        if(temp->next != nullptr) {
                            temp->next->prev = temp->prev;
                        }
                        Node* toDelete = temp;
                        temp = temp->next;
                        delete toDelete;
                        deletionCount++;
                    }
                }
                else {
                    temp = temp->next;
                }
            }
            if(deletionCount == 0) {
                std::cout << data << " Not found in the list!!\n";
            }
        }

        void deleteTheLastNode() {
            // Todo
        }

        void searchData(const std::string& inputData) {
            // Todo
        }

        void displayList() {
            Node* temp = head;
            while(temp) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << '\n';
        }
};

int main()
{
   DoubleLinkedList dll;
   std::cout << " Operations on a Double Linked List....\n";
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
                dll.insertAtBeg(data);
                break;
            case 2 :
                std::cout << "Enter the data: ";
                std::getline(std::cin, data);
                int pos;
                std::cout << "Enter the position: ";
                std::cin >> pos;
                dll.insertAtPos(data, pos);
                break;
            case 3 :
                std::cout << "Enter the data: ";
                std::getline(std::cin, data);
                dll.insertAtEnd(data);
                break;
            case 4 :
                std::cout << "\nThe list items: \n";
                dll.displayList();
                break;
            case 5 :
                std::cout << "\nEnter the data to be deleted: ";
                std::getline(std::cin, input);
                dll.deleteTheGivenData(input);
                break;
            case 6 :
                dll.deleteTheFirstNode();
                break;
            case 7 :
                dll.deleteTheLastNode();
                break;
            case 8 :
                std::cout << "Enter the data to be searched: ";
                std::getline(std::cin, searchString);
                dll.searchData(searchString);
                break;
            case 9 :
                std::cout << "\nCurrent List Items: \n";
                dll.displayList();
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