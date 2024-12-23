#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void rotateCounterclockwiseByKnodes(Node*& head, int k) {
    if (head == nullptr || k == 0) {
        return;
    }

    // Initialize pointers
    Node* current = head;
    int count = 1;

    // Count the number of nodes in the list
    while (current->next != nullptr) {
        current = current->next;
        count++;
    }

    // If k is greater than the number of nodes, take modulo
    k = k % count;

    // If k is 0 after modulo, no rotation is needed
    if (k == 0) {
        return;
    }

    // Traverse the list to find the k-th node
    current = head;
    for (int i = 1; i < k && current != nullptr; i++) {
        current = current->next;
    }

    // k-th node
    Node* kthNode = current;

    // Continue to traverse to find the last node
    while (current->next != nullptr) {
        current = current->next;
    }

    // Update pointers to rotate the list
    current->next = head; // Link last node to the head
    head = kthNode->next; // New head is the (k+1)-th node
    kthNode->next = nullptr; // k-th node is the new end of the list
}

// Helper function to print the list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a linked list 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 7; // Example where k is greater than the number of nodes
    rotateCounterclockwiseByKnodes(head, k);

    // Print the rotated list
    printList(head);

    // Clean up memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}