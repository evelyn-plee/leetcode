// Time Complexity: O(n), the whole tree is traversed once
// Space Complexity: O(n), the recursion goes up to a depth of n in the worst case

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
    int longestConsecutive(TreeNode* root) {
        helper(root);
        return ans;
    }
private:
    int ans;
    vector<int> helper(TreeNode* root){
        if(!root) return {0, 0};
        int inc = 1, dec = 1;
        if(root->left){
            vector<int> l = helper(root->left);
            if(root->val == root->left->val + 1) dec = (l[1]+1);
            else if(root->val == root->left->val - 1) inc = (l[0] +1);
        }
        if(root->right){
            vector<int> r = helper(root->right);
            if(root->val == root->right->val + 1) dec = max(dec, r[1]+1);
            else if(root->val == root->right->val -1) inc = max(inc, r[0]+1);
        }
        ans = max(ans, dec + inc -1);
        return {inc, dec};
    }
};
