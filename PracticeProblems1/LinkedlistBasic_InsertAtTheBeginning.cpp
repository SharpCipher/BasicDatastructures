#include <iostream>

using namespace std;

struct node{
    int data;
    struct node* next;
};

void Push(struct node** head, int val){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

struct node* BuildWithSpeciealCase(){
    struct node* head = nullptr;
    struct node* tail;
    
    int i;
    Push(&head, 1);
    tail = head;
    
    for(i=2; i<6; i++){
        Push(&(tail->next), i);
        tail = tail->next;
    }
    
    return head;
}

int main(){
    struct node* res = BuildWithSpeciealCase();
    while(res != nullptr){
        cout<<res->data<<endl;
        res = res->next;
    }
    return 0;
}