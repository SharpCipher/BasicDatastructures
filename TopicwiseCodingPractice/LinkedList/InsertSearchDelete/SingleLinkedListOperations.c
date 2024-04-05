#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    char* data;
    struct node* next;
};

struct node* head = NULL;

void insertAtBeg(char* data) {

}

void insertAtPos(char* data, int position) {
    
}

void insertAtEnd(char* data) {
    
}

void displayList() {

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
        char* data;
        int choice;
        scanf("%d", &choice);
        char* input;
        char* searchString;
        // Clear the input buffer before reading next input
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice) {
            case 1 :
                printf( "Enter the data: ");
                fgets(data, 20, stdin);
                insertAtBeg(data);
                break;
            case 2 :
                printf( "Enter the data: ");
                fgets(data, 20, stdin);
                int pos;
                printf( "Enter the position: ");
                scanf("%d", &pos);
                insertAtPos(data, pos);
                break;
            case 3 :
                printf( "Enter the data: ");
                fgets(data, 20, stdin);
                insertAtEnd(data);
                break;
            case 4 :
                printf( "\nThe list items: \n");
                displayList();
                break;
            case 5 :
                printf( "\nEnter the data to be deleted: ");
                fgets(input, 20, stdin);
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
                fgets(searchString, 20, stdin);
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