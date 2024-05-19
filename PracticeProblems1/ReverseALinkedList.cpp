#include<bits/stdc++.h>

using namespace std;

struct Node{
  int data;
  struct Node* next;
};
void Print(Node* head){
  Node* temp = head;
  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
Node* Insert(Node* head, int data){
  Node* temp = new Node();
  temp->data = data;
  temp->next = NULL;
  if(head == NULL){
    head = temp;
  }
  else{
    Node* temp1 = head;
    while(temp1->next != NULL){
      temp1 = temp1->next;
    }
    temp1->next = temp;
  }
  return head;
}

Node* Reverse(struct Node* head){
  Node* current;
  Node* pred;
  Node* succ;
  current = head;
  pred = NULL;
  while(current != NULL){
    succ = current->next;
    current->next = pred;
    pred = current;
    current = succ;
  }
  head = pred;
  return head;
}
int main(){
  Node* head = NULL;  //empty list
  head = Insert(head, 1); //List: 2
  head = Insert(head, 4);
  head = Insert(head, 6);
  head = Insert(head, 8);
  head = Insert(head, 2);
  head = Insert(head, 5);
  Print(head);
  head = Reverse(head);
  Print(head);
  return 0;
}
