class Solution{
    bool isValidBST(TreeNode* root, long long min, long long max){
        if(!root) return true;
        if(root->left){
            if(root->val <= root->left->val || root->left->val <= min) return false;
            else if(!isValidBST(root->left, min, root->val)) return false;
        }
        
        if(root->right){
            if(root->val >= root->right->val || root->right->val >= max) return false;
            else if(!isValidBST(root->right, root->val, max)) return false;
        }
        return true;
    }    

    public:
        bool isValidBST(TreeNode* root){
            return isValidBST(root, LLONG_MIN, LLONG_MAX);
        }
};