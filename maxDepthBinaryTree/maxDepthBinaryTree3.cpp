class Solution{
    public:
        int maxDepth(TreeNode* root){
            if (!root) return 0;
            int res = 0;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                ++res;
                int n = q.size();
                for(int i = 0; i < n; ++i){
                    TreeNode *t = q.front(); q.pop();
                    if(t->left) q.push(t->left);
                    if(t->right) q.push(t->right);
                }
            }
            return res;
        }
    }
};