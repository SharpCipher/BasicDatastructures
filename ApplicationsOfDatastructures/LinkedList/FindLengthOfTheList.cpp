#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = new Node;
    node->data = data;
    node->next = nullptr;
    return node;
}

// Function to find the length of the list - iterative approach
int findLength(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while(current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to find the length of the list - recursive approach
int countNodes(struct Node* head) {
    if(head == nullptr) {
        return 0;
    }
    return 1 + countNodes(head->next);
}

int main()
{
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(5);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(8);
    head->next->next->next->next->next = createNode(3);

    std::cout << "Length of the list using Iterative approach: " << findLength(head) << std::endl;
    std::cout << "Length of the list using Recursive approach: " << countNodes(head) << std::endl;

    delete head->next->next->next->next->next;
    delete head->next->next->next->next;
    delete head->next->next->next;

    std::cout << "Deleted 3 nodes" << std::endl;

    std::cout << "Length of the list using Iterative approach: " << findLength(head) << std::endl;
    std::cout << "Length of the list using Recursive approach: " << countNodes(head) << std::endl;

    delete head->next->next;
    delete head->next;
    delete head;
    head = nullptr;
    
    std::cout << "Deleted remaining nodes" << std::endl;

    std::cout << "Length of the list using Iterative approach: " << findLength(head) << std::endl;
    std::cout << "Length of the list using Recursive approach: " << countNodes(head) << std::endl;

    
    return 0;
}