#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *top1, *top2, *temp;

int count = 0;
void push(int val) {
    if(top1 == NULL) {
        top1 = (struct Node*)malloc(sizeof(struct Node));
        top1->data = val;
        top1->next = NULL;
    }
    else {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->next = top1;
        temp->data = val;
        top1 = temp;
    }
    count++;
    printf("Node inserted..\n");
}

int pop() {
    top2 = top1;
    if(top2 == NULL) {
        printf("\nStack Underflow!!\n");
        return -1;
    }
    else {
        top2 = top2->next;
    }
    int popped = top1->data;
    free(top1);
    top1 = top2;
    count--;
    return popped;
}

void display() {
    top2 = top1;
    if(top2 == NULL) {
        printf("\nStack Underflow!!\n");
        return;
    }
    printf("Stack is..\n");
    while(top2 != NULL) {
        printf("%d----->", top2->data);
        top2 = top2->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;
    printf("\nImplementation of Stack using Linked list\n");
    while(1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter the value to be pushed into stack: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                printf("\nPopped element is: %d", pop());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }
    return 0;
}