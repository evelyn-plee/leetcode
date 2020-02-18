class Solution{

public:
    vector<double> averageOfLevels(TreeNode* root){
    
        vector<int> count;
        vector<double> avgs;
        average(root, 0, count, avgs); 
        for(int i = 0; i < count.size(); i++){
            avgs[i] /= count[i];
        }
        return avgs;
    }

private:
    void average(TreeNode* root, int i, vector<int>& count, vector<int>& sum){
        if(root == null) return;
        
        if(count.size() <= i){
            count.push_back({});
        }
        if(sum.size() <= i){
            sum.push_back({});
        }
        
        count[i] += 1;
        sum[i] += root->val;
        
        average(root->left, i+1, count, sum);
        average(root->right, i+1, count, sum);
    }
}
