/*

Given the head of a linked list, rotate the list to the right by k places.

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Input: head = [0,1,2], k = 4
Output: [2,0,1]

@LeetCode
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* ptr = head;
        
        if(head == NULL || head->next == NULL)
            return head;
        int c = 1;
        
        while(temp->next != NULL){
            temp = temp->next;
            c++;
        }
        k = k%c;
        while(k--){
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = head;
            head = temp;
            ptr = temp;
            
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = NULL;
            temp = ptr;
        }
        return head;
    }
};