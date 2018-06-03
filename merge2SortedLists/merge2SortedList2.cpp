/**
 * Definition for singly-linked list
 * struct ListNode{
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL){}
 * };
 */
#include <ListNode>

class Solution{
    public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        if(!l1 && !l2) return NULL;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(l1 && l2){
            ListNode* newNode = new ListNode(0);
            if(l1->val < l2->val){
                newNode->val = l1->val;
                l1 = l1->next;
            } else{
                newNode->val = l2->val;
                l2 = l2->next;
            }
            temp->next = newNode;
            temp = temp->next;
        }
        if(l1) temp->next = l1;
        if(l2) temp->next = l2;
        return dummy->next;
    }
};