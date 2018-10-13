/** Time complexity: O(n), Space complexity: O(n) 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<long, pair<int,int>> counts; // key -> {id, count}
        vector<TreeNode*> ans;
        getId(root, counts, ans);
        return ans;
    }
private:
    int getId(TreeNode* root, 
              unordered_map<long, pair<int,int>>& counts,
              vector<TreeNode*>& ans) {
        if (!root) return 0;
        long key = (static_cast<long>(root->val) << 32) |
                   (getId(root->left, counts, ans) << 16) |
                    getId(root->right, counts, ans);
        
        auto it = counts.find(key);
        if (it == counts.end())
            it = counts.insert({key, {counts.size() + 1, 0}}).first;
        
        if (++it->second.second == 2)
            ans.push_back(root);        
                
        return it->second.first;
    }
};
