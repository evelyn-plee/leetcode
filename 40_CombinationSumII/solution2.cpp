class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        std::sort(candidates.begin(), candidates.end());
        vector<int> curr;
        dfs(candidates, target, 0, ans, curr);
        return ans;
    }
private:
    void dfs(const vector<int>& candidates, 
             int target, int s, 
             vector<vector<int>>& ans,              
             vector<int>& curr) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        
        for (int i = s; i < candidates.size(); ++i) {
            int num = candidates[i];
            if (num > target) return;
            if (i > s && candidates[i] == candidates[i - 1]) continue;
            curr.push_back(num);
            dfs(candidates, target - num, i + 1, ans, curr);
            curr.pop_back();
        }
    }
};
