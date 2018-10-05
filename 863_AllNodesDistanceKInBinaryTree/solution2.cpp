/**
Using DFS
*/


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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K){
        parent[root] = NULL;
        setParent(root);
        DFS(target, K);
        return res;
    }

private:
    unordered_map<TreeNode*, TreeNode*> parent;
    vector<int> res;
    set<int> visited;

    void setParent(TreeNode* node){
        if(!node) return;
        if(node->left){
            parent[node->left] = node;
            setParent(node->left);
        } 
        if(node->right){
            parent[node->right] = node;
            setParent(node->right);
        }
    }

    void DFS(TreeNode* node, int cur_val){
        if(visited.find(node->val) != visited.end()) return;
        visited.insert(node->val);
        if(cur_val == 0){
            res.push_back(node->val);
            return;
        }
        if(node->left) DFS(node->left, cur_val-1);
        if(node->right) DFS(node->right, cur_val-1);
        TreeNode* p = parent[node];
        if(p) DFS(p, cur_val-1);
    }
};
