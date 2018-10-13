/**
 * Time complexity: O(n*amount);
 * Space complexity: O(n)
 **/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = min coins to make up to amount i
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i)
                if (dp[i - coin] != INT_MAX)  
                    dp[i] = min(dp[i], dp[i - coin] + 1);
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
