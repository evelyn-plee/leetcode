/**
 * Definition for singly-linked list. 
 * struct ListNode{
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL){}
 * };
 */

#include <iostream>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        int cbit = 0;
        int a = 0;
        int b = 0;
        while(l1||l2)
        {
            int sum = ((l1)?(l1->val):(0)) + ((l2)?(l2->val):(0)) + cbit;
            curr->next = new ListNode(sum%10);
            cbit = sum/10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            curr = curr->next;
        }
        if (cbit)  
        {
            curr->next = new ListNode(cbit);    
        }
        return head->next;
    }
};