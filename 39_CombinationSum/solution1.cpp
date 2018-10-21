// Use backtracking

class Solution{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> res;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        combinationSum(candiates, target, 0, combination, res);
        return res;
    }
private:
    void combinationSum(vector<int>& candidates, int target, int start, vector<int>& combination, vector<vector<int>>& res){
        if(target == 0){
            res.push_back(combination);
            return;
        }
        for(int i = begin; i < candidates.size(); ++i){
            if(candidates[i] > target) return;
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidiates[i], i, combinaton, res);
            combination.pop_back();
        }
    }
};
