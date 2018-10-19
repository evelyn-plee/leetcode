// Time complexity: O(n), Space complexity: O(h)

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
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        helper(root, &res);
        return res;
    }
    
private:
    int helper(TreeNode* node, int* res){
        if(!node) return 0;
        
        int left = helper(node->left, res);
        int right = helper(node->right, res);
        
        int leftMax = 0, rightMax = 0;
        
        if(node->left && node->left->val == node->val) leftMax += left + 1;
        if(node->right && node->right->val ==node->val) rightMax += right + 1;
        *res = max(*res, leftMax + rightMax);
        return max(leftMax, rightMax);
    }
};
