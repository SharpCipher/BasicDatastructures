#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if(node == NULL) {
        printf("Memory allocation failed!!\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;

    return node;
}

void push(int data) {
    struct Node* temp = newNode(data);
    temp->next = head;
    head = temp;
}

// Function to print the linked list
void printList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* reverseKNodes(int k) {
    if(head == NULL || k <= 1) {
        return head;
    }
    struct Node* pred = NULL;
    struct Node* curr = head;
    struct Node* succ = NULL;
    int count = 0;

    // Traverse the list and reverse the first k nodes
    while(curr != NULL && count < k) {
        succ = curr->next;
        curr->next = pred;
        pred = curr;
        curr = succ;
        count++;
    }
    // Adjust the next pointer of the original head
    head->next = curr;

    // Return the new head after reversal
    return pred;
}

int main() {

    push(5);
    push(1);
    push(2);
    push(3);
    push(4);
    push(6);
    push(7);
    push(8);

    int k = 5;

    printf("Original list: \n");
    printList();

    head = reverseKNodes(k);

    printf("Reversed list: \n");
    printList();

    return 0;
}