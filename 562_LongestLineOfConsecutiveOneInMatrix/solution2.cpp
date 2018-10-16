// 3D dp O(m*n), O(m*n)

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
                if(M.size() == 0) return 0;
        int ones = 0;
        int m = M.size(), n = M[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4, 0)));
        
        for(int i = 0; i < m; i++){
            if(!M[i][0]) continue;
            dp[i][0] = {1, 1, 1, 1};
            dp[i][0][1] = !i ? 1 : dp[i-1][0][1] + 1;
            ones = max(ones, dp[i][0][1]);
        }

        for(int j = 0; j < n; j++){
            if(!M[0][j]) continue;
            dp[0][j] = {1, 1, 1, 1};
            dp[0][j][0] = !j ? 1 : dp[0][j-1][0] + 1;
            ones = max(ones, dp[0][j][0]);
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(!M[i][j]) continue;
                // same row, previous column == LEFT
                dp[i][j][0] = dp[i][j-1][0] + 1;
                // previous row, same column == UP
                dp[i][j][1] = dp[i-1][j][1] + 1;
                // previous row, previous column == TOP LEFT == DIAGONAL
                dp[i][j][2] = dp[i-1][j-1][2] + 1;
                ones = max(ones, max(dp[i][j][0], max(dp[i][j][1], dp[i][j][2])));
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(M[i][j]){
                    if(j+1 < n){
                        // TOP RIGHT == DIAGONAL
                        dp[i][j][3] = dp[i-1][j+1][3] + 1;
                        ones = max(ones, dp[i][j][3]);
                    }
                    else dp[i][j][3] = 1;
                }
            }
        }
        return ones;
    }
};
