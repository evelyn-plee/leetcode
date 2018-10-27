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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> cur, next;
        cur.push(root);
        vector<int> visited;
        int level = 0;
        while(!cur.empty()){
            auto p = cur.front(); cur.pop();
            visited.push_back(p->val);
            if(p->left) next.push(p->left);
            if(p->right) next.push(p->right);
            if(cur.empty()){
                if(level++ % 2) reverse(visited.begin(), visited.end());
                ans.push_back(visited);
                visited.clear();
                swap(cur, next);
            }
        }
        return ans;
    }
};
