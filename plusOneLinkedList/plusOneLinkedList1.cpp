/**
 * Definition for singly-linked list.
 * struct ListNode{
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL){}
 * }
*/  
#include<iostream>

class Solution{
public:
    ListNode* plusOne(ListNode* head){
        if(!head) return head;
        ListNode *rev_head = reverse(head), *cur = rev_head, *pre = cur;
        int carry = 1;
        while(cur){
            pre = cur;
            int sum = cur->val + carry;
            cur->val = sum % 10;
            carry = sum / 10;
            if(carry == 0) break;
            cur = cur->next;
        }
        if(carry) pre->next = new ListNode(1);
        return reverse(rev_head);
    }

    ListNode* reverse(ListNode* head){
        if(!head) return head;
        ListNode *dummy = new ListNode(-1), *cur = head;
        dummy->next = head;
        while(cur->next){
            ListNode *temp = cur->next;
            cur->next = temp->next;
            temp->next = dummy->next;
            dummy->next = temp;
        }
        return dummy->next;
    }
};