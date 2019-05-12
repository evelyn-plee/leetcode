/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val:
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution{
public:
    vector<int> largestValues(TreeNode* root){
        vector<int> ans;
        dfs(root, 1, ans);        
        return ans;
    }

private:
    void dfs(TreeNode* root, int curDepth, vector<int>& ans){
        if(!root) return;
        
        if(curDepth > ans.size()) ans.push_back(root->val);
        else ans[curDepth-1] = max(ans[curDepth-1], root->val);
        
        dfs(root->left, curDepth + 1, ans);
        dfs(root->right, curDepth + 1, ans);
    }
}
