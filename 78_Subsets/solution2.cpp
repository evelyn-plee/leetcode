// Iterative

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1, vector<int>());
        for(int i = 0; i < nums.size(); i++){
            int n = res.size();
            for(int j = 0; j < n; j++){
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};
