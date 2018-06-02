class Solution{
    public:
        bool isValidBST(TreeNode* root){
            if(!root) return true;
            TreeNode* pLast = NULL;
            stack<TreeNode*> st;
            while(root!=NULL || !st.empty()){
                while(root!=NULL){
                    st.push(root);
                    root=root->left;
                }
                root = st.top(); st.pop();
                if(!pLast) pLast = root;
                else if(pLast->val >= root->val) return false;
                pLast = root;
                root = root ->right;
            }
            return true;
        }
};