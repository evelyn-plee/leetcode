// Use backtracking

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, 0, cur, res);
        return res;
    }
private:
    void dfs(vector<int>& nums, int start, vector<int>& cur, vector<vector<int>>& res){
        res.push_back(cur);
        for(int i = start; i < nums.size(); ++i){
            cur.push_back(nums[i]);
            dfs(nums, i+1, cur, res);
            cur.pop_back();
        }
    }
};
