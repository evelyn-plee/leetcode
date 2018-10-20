// O(n^2), O(n^2)

class Solution{
public:
    bool PredictTheWinner(vector<int>& nums){
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for(int i = nums.size()-1; i >= 0; i--){
            for(int j = i+1; j < nums.size(); j++){
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }
        return dp[0][nums.size()-1] >= 0;
    }
};

// O(n^2), O(n)
class Solution1{
public:
    bool PredictTheWinner(vector<int>& nums){
        vector<int> dp(nums.size(),0);
        for(int i = nums.size()-1; i >= 0; i--){
            for(int j = i+1; j < nums.size(); j++){
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j-1]);
            }
        }
        return dp[nums.size()-1] >= 0;
    }
};
