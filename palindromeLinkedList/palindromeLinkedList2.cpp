/**
 * Definition for singly-linked list.
 * struct ListNode{
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL){}
 * };
 */
#include <ListNode>

/**
 * Follow up: O(n) time and O(1) space
 * Using stack won't achieve O(1) space
 * Reversing the next half, and compare
 */

class Solution{
    public:
    bool isPalindrome(ListNode* head){
        if(!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *last = slow->next, *pre = head;
        while(last->next){
            ListNode *temp = last->next;
            last->next = temp->next;
            temp->next = slow->next;
            slow->next = temp;
        }
        while(slow->next){
            slow = slow->next;
            if(pre->val != slow->val) return false;
            pre = pre->next;
        }
        return true;
    }
};
