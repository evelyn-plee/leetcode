/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode{
 *   int val;
 *   TreeLinkNode *left, *right, *next;
 *   TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
#include <iostream>
class Solution{
public:
    void connect(TreeLinkNode *root){
        TreeLinkNode *dummy = new TreeLinkNode(0), *t = dummy;
        while(root){
            if(root->left){
                t->next = root->left;
                t = t->next;
            }
            if(root->right){
                t->next = root->right;
                t = t->next;
            }
            root = root->next;
            if(!root){
                t = dummy;
                root = dummy->next;
                dummy->next = NULL;
            }
        }
    }
};