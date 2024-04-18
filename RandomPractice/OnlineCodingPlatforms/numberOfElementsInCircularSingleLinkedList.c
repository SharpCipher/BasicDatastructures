#include <stdio.h>
#include <stdlib.h>

// Node structure for a circular singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the circular linked list
struct Node* insertEnd(struct Node* last, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if (last == NULL) {
        new_node->next = new_node; // Point to itself if the list is empty
        last = new_node; // Update last to the new node
    } else {
        new_node->next = last->next; // Connect new node to the head
        last->next = new_node; // Connect the last node to the new node
        last = new_node; // Update last to the new node
    }

    return last;
}

// Function to find the number of elements in the circular linked list
int countElements(struct Node* last) {
    if (last == NULL)
        return 0;

    int count = 0;
    struct Node* temp = last->next; // Start from the head

    do {
        count++;
        temp = temp->next;
    } while (temp != last->next); // Stop when we reach the head again

    return count;
}

int main() {
    struct Node* last = NULL; // Last node of the circular linked list

    // Insert nodes into the circular linked list
    last = insertEnd(last, 1);
    last = insertEnd(last, 2);
    last = insertEnd(last, 3);
    last = insertEnd(last, 4);
    last = insertEnd(last, 5);

    // Find and print the number of elements in the circular linked list
    int numElements = countElements(last);
    printf("Number of elements in the circular linked list: %d\n", numElements);

    return 0;
}