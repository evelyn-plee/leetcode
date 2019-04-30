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
    bool isBalanced(TreeNode* root){
        int height = 0;
        return isBalancedHeight(root, height);
    }
    
private:
    bool isBalancedHeight(TreeNode* node, int& height){
        if(!node){
            height = 0;
            return true;
        }
        
        int lh, rh;
        if(!isBalancedHeight(node->left, lh)) return false;
        if(!isBalancedHeight(node->right, rh)) return false;
        
        height = max(lh, rh) + 1;
        return abs(lh-rh) <= 1;
    }
};
