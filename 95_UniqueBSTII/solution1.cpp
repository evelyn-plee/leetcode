// O(3^n) & O(3^n)

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
    vector<TreeNode*> generateTrees(int n){
        if(n==0) return {};
        const auto& ans = generateTrees(1, n);
        return ans;
    }
private:
    vector<TreeNode*> generateTrees(int l, int r){
        if(l > r) return {nullptr};
        vector<TreeNode*> ans;
        for(int i = l; i <= r; ++i){
            for(TreeNode* left : generateTrees(l, i-1)){
                for(TreeNode* right : generateTrees(i+1, r)){
                    ans.push_back(new TreeNode(i));
                    ans.back()->left = left;
                    ans.back()->right = right;
                }
            }
        }
        return ans;
    }
};
