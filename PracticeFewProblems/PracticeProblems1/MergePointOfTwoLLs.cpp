/*
Given pointers to the head nodes of 2 linked lists that merge together at some point, find the node where the two lists merge. 
The merge point is where both lists point to the same node, i.e. they reference the same memory location. 
It is guaranteed that the two head nodes will be different, and neither will be NULL. 
If the lists share a common node, return that node's data value.

Note: After the merge point, both lists will share the same node pointers. 

@HackerRank
*/



// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
SinglyLinkedListNode* node1 = head1;
SinglyLinkedListNode* node2 = head2;

while(node1 != node2){
    if(node1->next == NULL){
        node1 = head2;
    }
    else{
        node1 = node1->next;
    }
    if(node2->next == NULL){
        node2 = head1;
    }
    else{
        node2 = node2->next;
    }
}
return node2->data;

}

