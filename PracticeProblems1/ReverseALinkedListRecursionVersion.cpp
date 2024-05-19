#include<bits/stdc++.h>

using namespace std;

struct Node{
  int data;
  struct Node* next;
};
struct Node* head;
void Print(Node* p){
  if(p == NULL)
    return;
  printf("%d", p->data);
  Print(p->next);
}
struct Node* Insert(Node* head, int data){
  Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = NULL;
  if(head == NULL)
    head = temp;
  else{
    Node* temp1 = head;
    while(temp1->next != NULL)
      temp1 = temp1->next;
    temp1->next = temp;
  }
  return head;
}
struct Node* Reverse(struct Node* p){
  if(p->next == NULL){
    head = p;
    return head;
  }
  Reverse(p->next);
  struct Node* q = p->next;
  q->next = p;
  p->next = NULL;

  return head;
}

int main(){
  struct Node* head = NULL;
  head = Insert(head, 2);
  head = Insert(head, 4);
  head = Insert(head, 7);
  head = Insert(head, 3);
  head = Insert(head, 6);
  head = Insert(head, 9);
  Print(head);
  head = Reverse(head);
  cout<<endl;
  Print(head);
  cout<<endl;
  return 0;
}
