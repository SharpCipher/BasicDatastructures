#include<bits/stdc++.h>
using namespace std;
struct Node{
  int data;
  struct Node* next;
};
struct Node* head = NULL;
void Print(){
  Node* temp = head;
  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
struct Node* GetNewNode(int value){
  struct Node* newnode = new Node();
  newnode->data = value;
  newnode->next = NULL;
  return newnode;
}
void Push(int value){
  struct Node* newnode = GetNewNode(value);
  if(head == NULL){
    head = newnode;
    return;
  }
  newnode->next = head;
  head = newnode;
}
void Pop(){
  if(head == NULL)
    return;
  else{
    struct Node* temp;
    temp = head;
    head = head->next;
    free(temp);
  }
}
int main(){
  Push(5);
  Push(7);
  Push(2);
  Push(4);
  Print();
  Pop();
  Print();
  Pop();
  Print();
  Push(3);
  Print();
  Push(8);
  Print();
  Pop();
  Print();

  return 0;
}
