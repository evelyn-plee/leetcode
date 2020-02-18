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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        
        vector<double> avgs;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int curSize = q.size();
            double sum = 0.0;
            for(int i = 0; i < curSize; i++){
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            avgs.push_back(sum/curSize);
        }
        
        return avgs;
    }
};
