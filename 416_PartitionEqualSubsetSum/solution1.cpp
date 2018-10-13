//Time complexity: O(n*sum) Space complexity: O(sum)


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for(const int num : nums){
            for(int i = sum; i >= 0; --i){
                if(dp[i]) dp[i+num] = 1;
            }
            if(dp[sum/2]) return true;
        }
        return false;
    }
};
