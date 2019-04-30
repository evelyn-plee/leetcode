/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Backtracking
class Solution{
public:
    vector<string> binaryTreePaths(TreeNode* root){
        vector<string> paths;
        string path;
        constructPaths(root, path, paths);
        return paths;
    }
    
private:
    void constructPaths(TreeNode* root, string path, vector<int>& paths){
        if(!root) return;
        
        path += (path.empty() ? "" : "->") + to_string(root->val);
        if(!root->left && !root->right){
            paths.push_back(path);
        }else{
            constructPaths(root->left, path, paths);
            constructPaths(root->right, path, paths);
        }
    }
};

// Iterative 
