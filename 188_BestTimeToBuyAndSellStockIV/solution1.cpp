// O(nk), O(nk)

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(!k || !n) return 0;
        if(k >= (n/2)) return quickSolve(prices);
        
        vector<vector<int>> dp(k+1, vector<int>(n));
        for(int i = 1; i <= k; ++i){
            int maxDiff = -prices[0];
            for(int j = 1; j < n; ++j){
                dp[i][j] = max(dp[i][j-1], prices[j] + maxDiff);
                maxDiff = max(maxDiff, dp[i-1][j] - prices[j]);
            }
        }
        return dp[k][n-1];
    }
private:
    int quickSolve(vector<int>& prices){
        int len = prices.size(), profit = 0;
        for(int i = 1; i < len; ++i){
            if(prices[i] > prices[i-1]) profit += prices[i] - prices[i-1];
        }
        return profit;
    }
};


// O(n^2 k), O(nk)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(!k || !n) return 0;
        if(k >= (n/2)) return quickSolve(prices);
        
        vector<vector<int>> dp(k+1, vector<int>(n));
        for(int i = 1; i <= k; ++i){
            for(int j = 1; j < n; ++j){
                int maxVal = 0;
                for(int m = 0; m < j; ++m){
                    maxVal = max(maxVal, prices[j]-prices[m] + dp[i-1][m]);
                }
                dp[i][j] = max(dp[i][j-1], maxVal);
            }
        }
        return dp[k][n-1];
    }
private:
    int quickSolve(vector<int>& prices){
        int len = prices.size(), profit = 0;
        for(int i = 1; i < len; ++i){
            if(prices[i] > prices[i-1]) profit += prices[i] - prices[i-1];
        }
        return profit;
    }
};
