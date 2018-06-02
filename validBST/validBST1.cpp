class Solution{
public:
    bool isValidBST(TreeNode* root, TreeNode* l = NULL, TreeNode* r = NULL){
        if(!root) return true;
        if(l && l->val >= root->val) return false;
        if(r && r->val <= root->val) return false;
        return isValidBST(root->left, l, root) && isValidBST(root->right, root, r);
    }
};