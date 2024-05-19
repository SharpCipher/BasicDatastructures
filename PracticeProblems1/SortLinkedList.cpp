/*
Given the head of a linked list, return the list after sorting it in ascending order.

4->2->1->3

output: 1->2->3->4

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
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* a = head;
        ListNode* b = head;
        while(head != NULL){
            v.push_back(head->val);
            head = head->next;
        }
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++){
            a->val = v[i];
            a = a->next;
        }
        return b;
    }
};