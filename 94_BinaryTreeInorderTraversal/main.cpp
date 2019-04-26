// Recursive

class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> nodes;
        helper(root, nodes);
        return nodes;
    }
private:
    void helper(TreeNode* root, vector<int>& ans){
        if(root){
            if(root->left) helper(root->left, ans);
            ans.push_back(root->val);
            if(root->right) helper(root->right, ans);
        }
    }
};


// Iterative

class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> nodes;
        stack<TreeNode*> st;
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            nodes.push_back(root->val);
            root = root->right;
        }
        return nodes;
    }
};

// Morris Traversal

class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> nodes;
        while(root){
            if(root->left){
                TreeNode* pre = root->left;
                while(pre->right && pre->right != root){
                    pre = pre->right;
                }
                if(!pre->right){
                    pre->right = root;
                    root = root->left;
                }else{
                    pre->right = NULL;
                    nodes.push_back(root->val);
                    root = root->right;
                }
            }else{
                nodes.push_back(root->val);
                root = root->right;
            }
        }
        return nodes;
    }
}
