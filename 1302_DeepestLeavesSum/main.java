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

// Runtime is faster if values are stored in the map, compared to passing down reference of maxDepth, and sum.
