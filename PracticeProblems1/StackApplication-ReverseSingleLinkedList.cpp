#include<bits/stdc++.h>

using namespace std;

struct Node{
  int data;
  struct Node *next;
};
struct Node* head;

struct Node* GetNewNode(int value){
  struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
  newnode->data = value;
  newnode->next = NULL;
  return newnode;
}
struct Node* insert(struct Node* head, int value){
  struct Node* newnode = GetNewNode(value);
  if(head == NULL){
    head = newnode;
    return head;
  }
  struct Node* t = head;
  while(t->next != NULL){
    t = t->next;
  }
  t->next = newnode;
  return head;
}
void Print(struct Node* head){
  Node* temp = head;
  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
struct Node* Reverse(){
  if(head == NULL) return head;
  stack<struct Node*> S;
  struct Node* temp = head;
  while(temp->next != NULL){
    S.push(temp);
    temp = temp->next;
  }
  //temp = S.top();
  head = temp;
  //S.pop();
  while(!S.empty()){
    temp->next = S.top();
    S.pop();
    temp = temp->next;
  }
  temp->next = NULL;
  return head;
}

int main(){
  head = NULL;
  head = insert(head, 1);
  head = insert(head, 2);
  head = insert(head, 3);
  head = insert(head, 4);
  head = insert(head, 5);
  Print(head);
  cout<<endl;
  struct Node* res = Reverse();
  Print(res);
  cout<<endl;
  return 0;
}
