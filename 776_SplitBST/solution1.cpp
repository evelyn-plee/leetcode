// Time complexity: O(h), space complexity: O(n)


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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if(!root) return {NULL, NULL};
        else if(root->val <= V){
            vector<TreeNode*> bns = splitBST(root->right, V);
            root->right = bns[0];
            return {root, bns[1]};
        } else{
            vector<TreeNode*> bns = splitBST(root->left, V);
            root->left = bns[1];
            return {bns[0], root};
        }
    }
};
