// DP
// Time complexity: O(n^3), traverse the complete dp matrix once O(n^2). For every entry, take atmost n numbers a pivot.
// Space complexity: O(n^2)

class Solution{
public:
    int getMoneyAmount(int n){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int end = 2; end <= n; end++){
            for(int start = 1; start <= n-end+1; start++){
                int minRes = INT_MAX;
                for(int pivot = start; pivot < start+end-1; pivot++){
                    int res = pivot + max(dp[start][pivot-1], dp[pivot+1][start+end-1]);
                    minRes = min(minRes, res);
                }
                dp[start][start+end-1] = minRes;
            }
        }
        return dp[1][n];
    }
};
