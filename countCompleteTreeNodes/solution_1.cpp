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
    int countNodes(TreeNode* root) {
       if(!root) return 0;
        
        TreeNode *leftRoot = root, *rightRoot = root;
        int leftHeight = 0, rightHeight = 0;
        while(leftRoot){ 
            ++leftHeight; 
            leftRoot = leftRoot->left;
        }
        while(rightRoot){ 
            ++rightHeight; 
            rightRoot = rightRoot->right;
        }
        
        if(leftHeight == rightHeight) return pow(2, leftHeight) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
