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
        ListNode* l3 = NULL;
        ListNode** pNext = &l3;
        
        int carry = 0;
        
        while(l1 || l2){
            int i1 = l1 ? l1->val : 0;
            int i2 = l2 ? l2->val : 0;
            int i3 = (i1 + i2 + carry) % 10;
            carry = (i1 + i2 + carry) / 10;
            
            ListNode* &newNode = *pNext;
            newNode = new ListNode(i3);
            pNext = &(newNode->next);
            
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        
        if(carry != 0){
            *pNext = new ListNode(carry);
        }
        
        return l3;
    }
};