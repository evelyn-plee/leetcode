/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive
class Solution{
public:
   bool isSymmetric(TreeNode* root){
       return isMirror(root, root);
   }
   
private:
    bool isMirror(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        
        return (p->val == q->val) && isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }
};


// Iterative
class Solution{
public:
    bool isSymmetric(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty()){
            TreeNode* t1 = q.front(); q.pop();
            TreeNode* t2 = q.front(); q.pop();
            if(!t1 && !t2) continue;
            if(!t1 || !t2) return false;
            if(t1->val != t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return q.empty();
    }
}
