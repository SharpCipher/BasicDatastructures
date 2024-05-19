#include<bits/stdc++.h>
using namespace std;
struct Node{
  struct Node *prev;
  int data;
  struct Node *next;
};
struct Node *head;

void Print(){
  struct Node* temp = head;
  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void PrintReverse(){
  struct Node* temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->prev;
  }
  cout<<endl;
}

struct Node* GetNewNode(int value){
  struct Node *newnode = new Node();
  newnode->data = value;
  newnode->next = NULL;
  newnode->prev = NULL;
  return newnode;
}
void InsertAtHead(int value){
  struct Node* newnode = GetNewNode(value);
  if(head == NULL){
    head = newnode;
    return;
  }
  head->prev = newnode;
  newnode->next = head;
  head = newnode;
}

void InsertAtEnd(int value){
  struct Node* newnode = GetNewNode(value);
  newnode->data = value;
  newnode->prev = NULL;
  newnode->next = NULL;
  struct Node* temp;
  temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newnode;
  newnode->prev = temp;
  temp = newnode;
}

int main(){
  head = NULL;
  InsertAtHead(5);
  InsertAtHead(1);
  InsertAtHead(3);
  InsertAtHead(2);
  InsertAtHead(8);
  InsertAtHead(6);

  Print();
  PrintReverse();

  InsertAtEnd(4);
  InsertAtEnd(7);
  InsertAtEnd(9);
  InsertAtEnd(0);

  Print();
  PrintReverse();
  return 0;
}
