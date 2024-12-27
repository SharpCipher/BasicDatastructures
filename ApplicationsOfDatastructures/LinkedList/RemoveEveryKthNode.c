#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to remove every kth node from the linked list
struct Node* deleteKthNode(struct Node* head, int k) {
    // If list is empty or k is 0, return head
    if(head == NULL || k == 0) {
        return head;
    }

    struct Node* curr = head;
    struct Node* prev = NULL;

    int count = 0;

    while(curr != NULL) {
        count++;

        // If count is multiple of k, remove current node
        if(count % k == 0) {
            // Skip the current node
            if(prev != NULL) {
                prev->next = curr->next;
            }
            else {
                head = curr->next;
            }

            free(curr);
            curr = (prev != NULL) ? prev->next : head;
        }
        else {
            // Update previous node pointer only if current node is not removed
            prev = curr;
            curr = curr->next;
        }
    }

    return head;

}

void printList(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);

    int k = 2;
    head = deleteKthNode(head, k);
    printList(head);

    return 0;
}