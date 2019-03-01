/**
 * The idea is to traverse tree, and at each non-empty node we return the excess coins 
 * but also keeping track of the overall move needed at *res.
 * Time Complexity: O(n), visit each node once at O(1) operation each
 * Space Complexity: O(d), maximum depth of the tree
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution{
public:
    int distributeCoins(TreeNode* root){
        int ans = 0;
        balanceHelper(root, ans);
        return ans;
    }
    
    int balanceHelper(TreeNode* root, int& ans){
        if(root == NULL) return 0;
        int l = balanceHelper(root->left, ans);
        int r = balanceHelper(root->right, ans);
        // overall accumulator 
        ans += abs(1 - (root->val + l + r));
        // return the accumulated value from children + value itself excluding the coin needed for this node
        return root->val + l + r - 1;
    }
};
