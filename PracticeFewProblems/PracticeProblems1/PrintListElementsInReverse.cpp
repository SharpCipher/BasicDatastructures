#include<bits/stdc++.h>

using namespace std;

struct Node{
  int data;
  struct Node* next;
};
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
void Print(struct Node* p){
  if(p == NULL)
    return;
  printf("%d", (*p).data);
  Print(p->next);
}
void Reverse(Node* head){
  if(head == NULL) return;
  Node* temp = head;
  Reverse(temp->next);
  printf("%d", (*temp).data);
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
  cout<<"\n";
  Reverse(head);
  return 0;
}
