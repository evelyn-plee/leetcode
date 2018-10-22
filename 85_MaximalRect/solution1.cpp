// O(mn^2), O(mn)

struct MaxHW{ int h, w;};

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m = matrix.size(); 
        if(matrix.empty() || !m) return 0;
        int n = matrix[0].size();
        vector<vector<MaxHW>> dp(m, vector<MaxHW>(n));
        
        for(int i = m-1; i >=0; --i){
            for(int j = n-1; j >= 0; --j){
                dp[i][j] = (matrix[i][j] == '1') ?  MaxHW{i + 1 < m ? dp[i+1][j].h + 1 : 1,
                                                j + 1 < n ? dp[i][j+1].w + 1 : 1}: MaxHW{0, 0};
            }
        }
    
        int maxRectArea = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == '1' && dp[i][j].h * dp[i][j].w > maxRectArea){
                    int minWidth = numeric_limits<int>::max();
                    for(int a = 0; a < dp[i][j].h ; ++a){
                        minWidth = min(minWidth, dp[i+a][j].w);
                        maxRectArea = max(maxRectArea, minWidth * (1+a));
                    }
                } 
            }
        }
        return maxRectArea;
    }
};
