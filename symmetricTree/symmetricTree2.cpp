class Solution{
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        return isMetric(left, right);
    }
    
    bool isMetric(TreeNode *p, TreeNode *q){
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val == q->val) {
            return isMetric(p->left, q->right) && isMetric(p->right, q->left);
        } else
            return false;
    }
};