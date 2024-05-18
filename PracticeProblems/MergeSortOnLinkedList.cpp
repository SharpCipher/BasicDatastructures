/*
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution{
  public:
    // Function to split the list
    Node* get_middle(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    // Merge two Sorted lists
    Node* sortedMerge(Node* head1, Node* head2) {
        Node* head = new Node(0);
        Node* curr = head;
        
        while(head1 != NULL && head2 != NULL) {
            if(head1->data <= head2->data){
                curr->next = head1;
                head1 = head1->next;
                curr = curr->next;
            }
            else {
                curr->next = head2;
                head2 = head2->next;
                curr = curr->next;
            }
        }
        if(head1 != NULL)
            curr->next = head1;
        if(head2 != NULL)
            curr->next = head2;
            
        return head->next;
    }
  
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head == NULL || head->next == NULL) {
            return head;
        }
        Node* mid = get_middle(head); // To split the list into two halves
        Node* newlist = mid->next;  // Assign the second half of the list as newlist pointer
        mid->next = NULL;
        Node* left = mergeSort(head); // Sorting the first half list
        Node* right = mergeSort(newlist); // Sorting the second half list
        
        return sortedMerge(left, right); // Merging of two lists
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}