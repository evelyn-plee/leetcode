/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution{
public:
    ListNode* plusOne(ListNode* head){
        if(!head) return NULL;
        int carry = helper(head);

        if(carry == 1){
            ListNode *dummy = new ListNode(1);
            dummy->next = head;
            return dummy;
        }
        return head;
    }

    int helper(ListNode* node){
        if(!node) return 1;
        int carry = helper(node->next);
        int sum = node->val + carry;
        node->val = sum % 10;
        return sum / 10;
    }
};