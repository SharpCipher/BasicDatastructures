#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* ptr;
};

struct node* front = NULL;
struct node* rear = NULL;

// Enqueue operation inserts element in queue
void enqueue(int element) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->ptr = NULL;
    if((front == NULL) && (rear == NULL)) {
        front = rear = newnode;
    }
    else {
        rear->ptr = newnode;
        rear = newnode;
    }
    printf("Node inserted!!\n");
}

// Dequeue operation deletes element from queue

int dequeue() {
    if(front == NULL) {
        printf("Underflow : Queue is empty!!\n");
        return -1;
    }
    else {
        struct node* temp = front;
        int tempData = front->data;
        front = front->ptr;
        free(temp);
        return tempData;
    }
}

// Display all elements in a queue
void display() {
    if((front == NULL) && (rear == NULL)) {
        printf("\nQueue is empty!!\n");
    }
    else {
        printf("\nThe Queue is: \n");
        struct node* temp;
        temp = front;
        while(temp) {
            printf("%d--->", temp->data);
            temp = temp->ptr;
        }
        printf("NULL\n\n");
    }
}

int main() {
    int ch, element;
    do{
        printf("1. Enqueue\n2.Dequeu\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: 
                printf("\nEnter the element to insert: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                printf("Deleted element is: %d\n", dequeue());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nWrong choice!!\n");
        }
    }while(ch != 4);
    return 0;
}