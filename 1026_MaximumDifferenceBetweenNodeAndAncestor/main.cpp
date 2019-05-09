class Solution{
public:
    int maxAncestorDiff(TreeNode* root){
        return dfs(root, root->val, root->val);
    }
    
private:
    int dfs(TreeNode* root, int mn, int mx){
        if(root == NULL) return mx - mn;
        mn = min(mn, root->val);
        mx = max(mx, root->val);
        return max(dfs(root->left, mn, mx), dfs(root->right, mn, mx));
    }
}
