#include<bits/stdc++.h>

struct Node{
  int data;
  struct Node *next;
};
struct Node* head;
//Inserting data at nth position(Middle of the LinkedList)
void Insert(int data, int n){
  Node* temp1 = new Node();  //Node* temp = (Node*)malloc(sizeof(struct Node));
  temp1->data = data; // (*temp).data = x;
  temp1->next = NULL;
  if(n == 1){  //Inserting in the beginning of the list(at head)
    temp1->next = head;
    head = temp1;
    return;
  }

  Node* temp2 = head;
  for(int i=0;i<n-2;i++){ //Traverse till n-2 th position
    temp2 = temp2->next; //Now it's at n-1 th position
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
}

void Print(){
  Node* temp = head;
  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main(){
  head = NULL;  //empty list
  Insert(2,1); //List: 2
  Insert(3,2); //List: 2, 3
  Insert(4,1); //List: 4,2,3
  Insert(5,2); //List: 4,5,2,3
  Print();
}


/*From HackerRank Builtin functions..*/

#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    SinglyLinkedListNode *temp = llist;
    int i = 0;
    while(i != position-1){
        i++;
        temp = temp->next;
    }
    
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
    return llist;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }

    int data;
    cin >> data;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);

    print_singly_linked_list(llist_head, " ", fout);
    fout << "\n";

    free_singly_linked_list(llist_head);

    fout.close();

    return 0;
}
