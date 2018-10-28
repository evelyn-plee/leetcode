//O(n), O(h)

class Solution{
public:
    int minDiffInBST(TreeNode* root){
        int res = INT_MAX, prev = INT_MIN;
        helper(root, prev, res);
        return res;
    }
private:
    void helper(TreeNode* root, int& prev, int& res){
        if(root){
            helper(root->left, prev, res);
            if(prev != INT_MIN) res = min(res, root->val - prev);
            prev = root->val;
            helper(root->right, prev, res);
        }
    }
};
