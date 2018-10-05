class Solution {
public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    ans.clear();
    dis(root, target, K);
    return ans;
  }
private:
  vector<int> ans;
  // Returns the distance from root to target.
  // Returns -1 if target does not in the tree.
  int dis(TreeNode* root, TreeNode* target, int K) {
    if (root == nullptr) return -1;
    if (root == target) {
      collect(target, K);
      return 0;
    }
    
    int l = dis(root->left, target, K);
    int r = dis(root->right, target, K);
    
    // Target in the left subtree
    if (l >= 0) {
      if (l == K - 1) ans.push_back(root->val);
      // Collect nodes in right subtree with depth K - l - 2
      collect(root->right, K - l - 2);
      return l + 1;
    }
    
    // Target in the right subtree
    if (r >= 0) {
      if (r == K - 1) ans.push_back(root->val);
      // Collect nodes in left subtree with depth K - r - 2
      collect(root->left, K - r - 2);
      return r + 1;
    }
    
    return -1;
  }
  
  // Collect nodes that are d steps from root.
  void collect(TreeNode* root, int d) {
    if (root == nullptr || d < 0) return;
    if (d == 0) ans.push_back(root->val);
    collect(root->left, d - 1);
    collect(root->right, d - 1);
  }
};
