/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// BFS Approach
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            res = 0;
            for(int i = 0; i < size; i++){
                TreeNode* root = q.front(); q.pop();
                res += root->val;
                if(root->left != nullptr) q.push(root->left);
                if(root->right != nullptr) q.push(root->right);
            }
        }
        return res;
    }
};

// DFS Approach

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!dfs(root, 0)) return 0;
        return sumMap[maxDepth];
    }
    
private:
    int maxDepth{0};
    unordered_map<int, int> sumMap;
    
    bool dfs(TreeNode* node, int curLevel){
        if(!node) return false; 
        
        if( curLevel >= maxDepth ){
            maxDepth = curLevel;
            sumMap[maxDepth] += node->val;
        }
        dfs(node->left, curLevel + 1);
        dfs(node->right, curLevel + 1);
        
        return true;
    }
};   

// or can pass down maxDepth, sum as references
