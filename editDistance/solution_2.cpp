#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    // Maintains 2 columns: previous column, current column
    // Need not maintain the full m*n matrix
    int minDistance(string word1, string word2) {
        if (word1.empty()) return word2.size();
        if (word2.empty()) return word1.size();
        
        int m = word1.size(), n = word2.size();
        if (m < n) return minDistance(word2, word1);
        
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j;
        }
        
        bool bidx;
        for (int i = 1; i <=m; ++i) {
            bidx = (i%2 != 0);
            for (int j = 0; j <=n; ++j)
            {
                if (j == 0) {
                    dp[bidx][j] = dp[1-bidx][j] + 1;
                }
                else if (word1[i-1] == word2[j-1]) {
                    dp[bidx][j] = dp[1-bidx][j-1];
                }
                else {
                    int step = min(dp[bidx][j-1], dp[1-bidx][j]);
                    dp[bidx][j] = 1 + min(step, dp[1-bidx][j-1]);
                }
            }
        }
        return dp[bidx][n]; 
    }  
};