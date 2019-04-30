/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 class Recursive_Solution{
 public:
    bool hasPathSum(TreeNode* root, int sum){
        if(!root) return false;
        sum -= root->val;
        if(!root->left && !root->right) return sum == 0;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
 };
 
 class Iterative_Solution{
 public:
    bool hasPathSum(TreeNode* root, int sum){
        if(!root) return false;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, sum - root->val});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int remainingSum = q.front().second;
            q.pop();
            if(node && !node->left && !node->right){
                if(!remainingSum) return true;
                continue;
            }
            if(node->left) q.push({node->left, remainingSum - node->left->val});
            if(node->right) q.push({node->right, remainingSum - node->right->val});
        }
        return false;
    }
 }
 
 
