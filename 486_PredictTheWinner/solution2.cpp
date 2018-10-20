// Time complexity: O(n^2), Space complexity: O(n^2)

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        m_ = vector<vector<int>>(nums.size(), vector<int>(nums.size(), INT_MIN));
        return getScore(nums, 0, nums.size()-1) >= 0;   
    }
private:
    vector<vector<int>> m_;
    int getScore(vector<int>& nums, int l, int r){
        if(l == r) return nums[l];
        if(m_[l][r] != INT_MIN) return m_[l][r];
        m_[l][r] = max(nums[l] - getScore(nums, l+1, r), nums[r] - getScore(nums, l, r-1));
        return m_[l][r];
    }
};
