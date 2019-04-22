// Copy array
// Time complexity: nlogn - n^2
// Space complexxity: nlogn - n^2

class Solution{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums){
        if(nums.empty()) return nullptr;
        
        auto it = max_element(nums.begin(), nums.end());
        vector<int> left(nums.begin(), it);
        vector<int> right(nums.begin(), it);
        
        TreeNode* root = new TreeNode(*it);
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};


// Without copying array
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructHelper(nums, 0, nums.size());
    }
private:
    TreeNode* constructHelper(const vector<int>& nums, int begin, int end){
        if(begin >= end) return nullptr;
        
        auto it = max_element(nums.begin() + begin, nums.begin() + end);
        int mIdx = it - nums.begin();
        
        TreeNode* root = new TreeNode(*it);
        root->left = constructHelper(nums, begin, mIdx);
        root->right = constructHelper(nums, mIdx+1, end);
        return root;
    }
};
