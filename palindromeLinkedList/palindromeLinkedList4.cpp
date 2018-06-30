/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static int x = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}();
class Solution {
public:
    ListNode* reserveList(ListNode *root) {
        if (root == NULL) return NULL;
        ListNode *pri = root;
        ListNode *now = root->next;
        ListNode *temp;
        while (now != NULL) {
            temp = now->next;
            now->next = pri;
            pri = now;
            now = temp;
        }
        root->next = NULL;
        return pri;
    }
    bool isPalindrome(ListNode *head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode *fast = head, *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reserveList(slow->next);

        ListNode *left = head;
        ListNode *right = slow->next;
        while (right != NULL) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};