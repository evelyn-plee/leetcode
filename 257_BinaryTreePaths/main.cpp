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
class Solution1{
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
class Solution2{
public:
    vector<string> binaryTreePaths(TreeNode* root){
        if(!root) return {};
        
        vector<string> paths;
        queue<pair<TreeNode*, string>> todo;
        todo.push({root, to_string(root->val)});
        while(!todo.empty()){
            TreeNode* node = todo.front().first;
            string path = todo.front().second;
            todo.pop();
            if(!node->left && !node->right){
                paths.push_back(path);
            }else{
                if(node->left) todo.push({node->left, path + "->" + to_string(node->left->val)});
                if(node->right) todo.push({node->right, path + "->" + to_string(node->right->val)});
            }
        }
        return paths;
    }
}
