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


class Morris_Traversal_Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root, *prev = NULL;
        int deep = 0;
        while (cur) {
            if (cur->left == NULL) {
                //
                if (deep >= res.size())
                    res.push_back(cur->val);
                else
                    res[deep] = max(res[deep], cur->val);
                cur = cur->right;
                deep++;
            } else {
                prev = cur->left;
                int move = 1;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                    move++;
                }
                if (prev->right == NULL) {
                    if (deep >= res.size())
                        res.push_back(cur->val);
                    prev->right = cur;
                    cur = cur->left;
                    deep++;
                } else {
                    // back to parent node, remove connection
                    prev->right = NULL;
                    deep -= move + 1;
                    //
                    if (deep >= res.size())
                        res.push_back(cur->val);
                    else
                        res[deep] = max(res[deep], cur->val);
                    cur = cur->right;
                    deep++;
                }
            }
        }
        return res;
    }
};
