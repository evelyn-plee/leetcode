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
    vector<vector<int>> levelOrder(TreeNode* root){                 
        vector<vector<int>>ans;
        vector<int> a;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n= q.size();
            for (int i=0;i<n;i++){
                TreeNode* t= q.front(); q.pop();
                a.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                if(i==n-1){
                    ans.push_back(a);
                    a.clear();
                }
            }
        }
        return ans;
    }
};
