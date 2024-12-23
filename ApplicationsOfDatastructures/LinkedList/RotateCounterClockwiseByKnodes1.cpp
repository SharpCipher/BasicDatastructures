/*
Given a singly linked list, The task is to rotate the linked list counter-clockwise by k nodes.
Input: linked list = 10->20->30->40->50->60, k = 4
Output: 50->60->10->20->30->40. 
Explanation: k is smaller than the count of nodes in a linked list so (k+1 )th node i.e.
50 becomes the head node and 60’s next points to 10

Input: linked list = 30->40->50->60, k = 2
Output: 50->60->30->40.
*/

#include <iostream>

class Node {
    public:
        int data;
        Node* next;
        Node(const int& data) : data(data), next(nullptr) {};
};

class SingleLinkedList{
    private:
        Node* head;
    public:
        SingleLinkedList(){
            head = nullptr;
        }
        void push(const int& data) {
            Node* newNode = new Node(data);
            newNode->data = data;
            newNode->next = head;
            head = newNode;
        }

        void printList() {
            Node* temp = head;
            while(temp) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << '\n';
        }

        void rotateCounterclockwiseByKnodes(int k) {
            if(k == 0)
                return;
            Node* curr = head;
            int nodeCount = 1;

            // Count the number of nodes in the linked list
            while(curr->next != nullptr) {
                curr = curr->next;
                nodeCount++;
            }

            if(k > nodeCount) {
                k = k%nodeCount;
            }

            int c = 1;
            while(c < k  &&  curr != nullptr) {
                curr = curr->next;
                c++;
            }
            if(curr == nullptr) {
                return;
            }

            Node* kthNode = curr;

            while(curr->next != nullptr) {
                curr = curr->next;
            }

            curr->next = head;

            head  = kthNode->next;

            kthNode->next = nullptr;
        }
};

int main()
{
    SingleLinkedList sll;
    sll.push(9);
    sll.push(10);
    sll.push(5);
    sll.push(6);
    sll.push(7);
    sll.push(8);

    std::cout << "Given list: \n";
    sll.printList();

    sll.rotateCounterclockwiseByKnodes(3);

    std::cout << "List after rotation :\n";
    sll.printList();

    return 0;
}