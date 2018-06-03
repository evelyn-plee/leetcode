/**
 * Definition for a binary tree node.
 * struct TreeNode{
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <TreeNode>

class Solution{
    public:
    TreeNode* sortedArrayToBST(vector<int>& nums){
        if(nums.empty()) return NULL;
        if(nums.size()==1) return new TreeNode(nums[0]);
        int m = nums.size()/2;

        TreeNode* root = new TreeNode(nums[m]);
        auto v1 = vector<int>(nums.begin(), nums.begin()+m);
        auto v2 = vector<int>(nums.begin()+m+1, nums.end());
        root->left = sortedArrayToBST(v1);
        root->right = sortedArrayToBST(v2);
        return root;
    }
};