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
    inline int height(TreeNode* x){
        int ans=0;
        while(x)x=x->left,ans++;
        return ans;
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int ans=1,lh,rh;
        lh = height(root->left);
        while(lh){
            rh = height(root->right);
            if(lh==rh){
                root = root->right;
                ans = (ans<<1) + 1;
            }
            else{
                root = root->left;
                ans = (ans<<1);
            }
            lh--;
        }
        return ans;
        
    }
};
