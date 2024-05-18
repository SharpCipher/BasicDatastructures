/*Given the head of a singly linked list, return true if it is a palindrome.

Input: head = [1,2,2,1]
Output: true

Input: head = [1,2]
Output: false

@Leetcode

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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* temp = head;
        while(temp != nullptr){
            s.push(temp->val);
            temp = temp->next;
        }
        
        while(head != nullptr){
            int topElement = s.top();
            s.pop();
            if(head->val != topElement){
                return false;
            }
            
            head = head->next;
        }
        return true;
    }
};

