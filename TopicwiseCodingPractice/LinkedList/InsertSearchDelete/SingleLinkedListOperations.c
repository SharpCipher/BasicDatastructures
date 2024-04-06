#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define IN_DATA_STR 20

struct node {
    char data[IN_DATA_STR];
    struct node* next;
};

struct node* head = NULL;

void insertAtBeg(char* data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->data, data);
    newNode->next = head;
    head = newNode;
}

void insertAtPos(char* data, int position) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->data, data);

    int c = 1;
    struct node* curr = head;
    struct node* prev = NULL;
    while(curr) {
        if(position == c) {
            newNode->next = curr;
            if(prev)
                prev->next = newNode; 
            else
                head = newNode;

            return;
        }
        prev = curr;
        curr = curr->next;
        c++;
    }
    // If the position exceeds the size of the list, insert at the end
    if(position > c) {
        printf("Invalid position.\n");
        return;
    }
}

void insertAtEnd(char* data) {
    
}

void displayList() {
    struct node* ptr = head;
    while(ptr != NULL) {
        printf("%s -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void deleteTheGivenData(char* data) {

}

void deleteTheFirstNode(){

}

void deleteTheLastNode() {

}

void searchData(char* data) {

}

int main() {
    printf( " Operations on a Single Linked List....\n");
    bool shouldExit = false;
    while(!shouldExit) {
        printf( "\n1. Insert At beginning\n2. Insert At Position\n3. Insert At end\n");
        printf( "4. Display the list\n5. Delete the Given Data\n6. Delete the first node\n");
        printf( "7. Delete the last node\n8. Search data\n9. Exit\n");
        printf( "Enter your option: ");
        char data[IN_DATA_STR];
        int choice;
        scanf("%d", &choice);
        char input[IN_DATA_STR];
        char searchString[IN_DATA_STR];
        // Clear the input buffer before reading next input
        while((getchar()) != '\n');

        switch(choice) {
            case 1 :
                printf( "Enter the data: ");
                fgets(data, IN_DATA_STR, stdin);
                // Remove the new line charcter if present
                if(data[strlen(data) - 1] == '\n') {
                    data[strlen(data) - 1] = '\0';
                }
                insertAtBeg(data);
                break;
            case 2 :
                printf( "Enter the data: ");
                fgets(data, IN_DATA_STR, stdin);
                int pos;
                printf( "Enter the position: ");
                scanf("%d", &pos);
                // Remove the new line charcter if present
                if(data[strlen(data) - 1] == '\n') {
                    data[strlen(data) - 1] = '\0';
                }
                insertAtPos(data, pos);
                break;
            case 3 :
                printf( "Enter the data: ");
                fgets(data, IN_DATA_STR, stdin);
                // Remove the new line charcter if present
                if(data[strlen(data) - 1] == '\n') {
                    data[strlen(data) - 1] = '\0';
                }
                insertAtEnd(data);
                break;
            case 4 :
                printf( "\nThe list items: \n");
                displayList();
                break;
            case 5 :
                printf( "\nEnter the data to be deleted: ");
                fgets(input, IN_DATA_STR, stdin);
                deleteTheGivenData(input);
                break;
            case 6 :
                deleteTheFirstNode();
                break;
            case 7 :
                deleteTheLastNode();
                break;
            case 8 :
                printf( "Enter the data to be searched: ");
                fgets(searchString, IN_DATA_STR, stdin);
                searchData(searchString);
                break;
            case 9 :
                printf( "\nCurrent List Items: \n");
                displayList();
                printf( "Exiting...\n");
                shouldExit = true;
                break;
            default :
                printf( "Invalid option. Try again!!\n");
                break;
        }
   }
    return 0;
}