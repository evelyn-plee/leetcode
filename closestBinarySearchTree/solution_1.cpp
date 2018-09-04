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
    int ans = -1;
    double diff = -1.0;
 
    void dfs(TreeNode* root, double target){
        if(!root) return ;
        
        if(abs(target - root->val) < diff|| diff < 0){
            ans = root->val;
            diff = abs(target - ans);
        }
        
        if(root->val > target) dfs(root->left, target);
        else if(root->val < target) dfs(root->right, target);
        else return;
    }
 
    int closestValue(TreeNode* root, double target){
        dfs(root, target);
        return ans;
    }
};
