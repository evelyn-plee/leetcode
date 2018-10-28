class Solution{
public:
    TreeNode* trimBST(TreeNode* root, int L, int R){
        if(root == NULL) return NULL;
        if(root->val < L) return trimBST(root->right, L, R);
        if(root->val > R) return trimBST(root->left, L, R);
        root->left = trim(root->left, L , R);
        root->right = trim(root->right, L, R);
        return root;
    }
};
