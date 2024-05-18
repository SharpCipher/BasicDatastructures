#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node* next;
};

struct Node* head;

void Print(){
  Node* tempo = head;
  while(tempo != NULL){
    printf("%d ", tempo->data);
    tempo = tempo->next;
  }
  printf("\n");
}

void Insert(int data){
  struct Node* node = new Node();
  node->data = data;
  if(head == NULL){
    node->next = head;
    head = node;
    return;
  }
  struct Node* temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = node;
  node->next = NULL;

} //Insert an integer at the end of List
void Delete(int n){
  struct Node* temp1 = head;
  if(n == 1){
    head = temp1->next;
    free(temp1);
    return;
  }
  int i;
  for(i=0;i<n-2;i++){
    temp1 = temp1->next;
  }
  struct Node* temp2 = temp1->next;
  temp1->next = temp2->next;
  free(temp2);
}

int main(){
  head = NULL; //empty List
  Insert(2);
  Insert(4);
  Insert(6);
  Insert(5); //List: 2 4 6 5
  Insert(1);
  Print();
  int n;
  cout<<"Enter a position\n";
  cin>>n;
  Delete(n);
  Print();
  return 0;
}
