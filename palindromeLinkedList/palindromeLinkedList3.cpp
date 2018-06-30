#include <iostream>

class Solution{
public:
    bool isPalindrome(ListNode* head){
        int n = 0;
        ListNode *curr = head;
        while(!curr){curr = curr->next; n++;}
        if(n <= 1) return true;

        //reverse half of the List
        int mid = n/2;
        ListNode *prev = NULL;
        curr = head;
        while(mid && !curr){
            ListNode* next = curr->next;
            curr->next = prev; 
            prev = curr;
            curr = next; 
            --half;
        }

        //compare prev with curr or curr->next
        if(n%2) curr = curr->next;
        while(!curr){
            if(curr->val != prev->val) return false;
            curr = curr->next;
            prev = prev->next;
        }
        return true;
    }
};