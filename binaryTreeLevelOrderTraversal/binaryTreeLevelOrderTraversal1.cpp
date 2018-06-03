#include <vector>
class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> levelNodeValues;
        if(!root) return levelNodeValues;

        vector<TreeNode*> *curLevel = new vector<TreeNode*>();
        vector<TreeNode*> *nextLevel = new vector<TreeNode*>();
        curLevel->push_back(root);

        while(!curLevel->empty()){
            vector<int> curLevelValues;
            for (int i = 0; i < curLevel->size(); i++){
                TreeNode *curNode = (*curLevel)[i];
                curLevelValues.push_back(curNode->val);
                if(curNode->left) nextLevel->push_back(curNode->left);
                if(curNode->right) nextLevel->push_back(curNode->right);
            }
            levelNodeValues.push_back(curLevelValues);

            vector<TreeNode*> *temp = curLevel;
            curLevel = nextLevel;
            nextLevel = temp;
            nextLevel->clear();
        }
        return levelNodeValues;
    }
};