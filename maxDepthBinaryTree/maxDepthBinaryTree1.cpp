class Solution{
    public:
    int maxDepth(TreeNode* root){
        int d = 1;
        return root ? max(depth(root->left,d), depth(root->right,d)) : 0;
    }
    
    int depth(TreeNode* root, int d){
        if(!root) return d;
        else{
            d++;
            return max(depth(root->left,d), depth(root->right,d));
        }
    }
};