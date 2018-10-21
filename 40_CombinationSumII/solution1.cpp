class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        std::sort(candidates.begin(), candidates.end());
        vector<int> curr;
        dfs(candidates, target, 0, ans, curr);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
private:
    void dfs(const vector<int>& candidates, 
             int target, int s, 
             set<vector<int>>& ans,              
             vector<int>& curr) {
        if (target == 0) {
            ans.insert(curr);
            return;
        }
        
        for (int i = s; i < candidates.size(); ++i) {
            int num = candidates[i];
            if (num > target) return;
            curr.push_back(num);
            dfs(candidates, target - num, i + 1, ans, curr);
            curr.pop_back();
        }
    }
};
