#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty()) return word2.size();
        if (word2.empty()) return word1.size();
        
        int m = word1.size(), n = word2.size();
        if (m < n) return minDistance(word2, word1);
        
        vector<int> dp(n+1, 0);
        for (int j = 1; j <= n; j ++) {
            dp[j] = j;
        }
        
        int prev_row = 0, diagonal = 0;
        for (int i = 1; i <=m; i ++) {
            dp[0] = i;
            diagonal = i-1;
            
            for (int j = 1; j <=n; j ++)
            {
                prev_row = dp[j];

                if (word1[i-1] == word2[j-1]) {
                    dp[j] = diagonal;
                }
                else {
                    int step = min(dp[j-1], prev_row);
                    dp[j] = 1 + min(step, diagonal);
                }

                diagonal = prev_row;
                prev_row = dp[j];
            }
        }
        
        return dp[n]; 
    }
};