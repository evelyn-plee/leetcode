/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        return helper(root, 1, 1);
    }

private:
    int helper(TreeNode* node, int p, int gp){
        return node ? helper(node->left, node->val, p) + 
                      helper(node->right, node->val, p) + 
                      (gp % 2 == 0 ? node->val : 0) 
                    : 0;
    }
};
