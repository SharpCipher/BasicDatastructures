/*

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        else{
            ListNode* res = new ListNode(-1);
            ListNode* t = res;
            ListNode *p1 = list1;
            ListNode *p2 = list2;
            
            while(p1 != NULL && p2 != NULL){
                if(p1->val >= p2->val){
                    res->next = p2;
                    res = res->next;
                    p2 = p2->next;
                }
                else{
                    res->next = p1;
                    res = res->next;
                    p1 = p1->next;
                }
            }
            
            while(p1 != NULL){
                res->next = p1;
                p1 = p1->next;
                res = res->next;
            }
            while(p2 != NULL){
                res->next = p2;
                p2 = p2->next;
                res = res->next;
            }
            t = t->next;
            return t;
        }
        
    }
};
