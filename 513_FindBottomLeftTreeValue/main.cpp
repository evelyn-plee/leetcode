class DFS_Solution{
public:
    int findBottomLeftValue(TreeNode* root){
        int maxDepth = 0, leftVal = root->val;
        helper(root, maxDepth, 0, leftVal);
        return leftVal;
    }
    
private:
    void helper(TreeNode* root, int& maxDepth, int curDepth, int& leftVal){
        if(root == NULL) return;
        
        helper(root->left, maxDepth, curDepth+1, leftVal);
        helper(root->right, maxDepth, curDepth+1, leftVal);
        
        if(curDepth > maxDepth){
            maxDepth = curDepth;
            leftVal = root->val;
        }
    }
};

class BFS_Solution{
public:
    int findBottomLeftValue(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            root = q.front(); q.pop();
            if(root->right) q.push(root->right);
            if(root->left) q.push(root->left);
        }
        return root->val;
    }
}
