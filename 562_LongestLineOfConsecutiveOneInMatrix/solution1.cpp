// Brute Force: Time complexity, O(mn), Space complexity, O(1)

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int m = M.size(), n = m ? M[0].size():0;
        int maxLine = 0, line = 0; 
        for(int i = 0; i < m; ++i){
            line = 0; 
            for(int j = 0; j < n; ++j){
                line = M[i][j] ? line+1:0;
                maxLine = maxLine > line ? maxLine:line; 
            }
        }
        
        for(int j = 0; j < n; ++j){
            line = 0;
            for(int i = 0; i < m; ++i){
                line = M[i][j] ? line+1:0;
                maxLine = maxLine > line ? maxLine:line; 
            }
        }
        
        for(int i = 0; i < m; ++i){
            line = 0;
            for(int k = i, j = 0; k < m && j < n; ++k, ++j){
                line = M[k][j] ? line+1:0;
                maxLine = maxLine > line ? maxLine:line; 
            }
        }
        
        for(int i = 0; i < n; ++i){
            line = 0;
            for(int k = 0, j = i; k < m && j < n; ++k, ++j){
                line = M[k][j] ? line+1:0;
                maxLine = maxLine > line ? maxLine:line; 
            }
        }
        
        for(int i = 0; i < m; ++i){
            line = 0;
            for(int k = i, j = 0; k >= 0 && j < n; --k, ++j){
                line = M[k][j] ? line+1:0;
                maxLine = maxLine > line ? maxLine:line; 
            }
        }
        
        for(int i = 0; i < n; ++i){
            line = 0;
            for(int k = m-1, j = i; k >= 0 && j < n; --k, ++j){
                line = M[k][j] ? line+1:0;
                maxLine = maxLine > line ? maxLine:line; 
            }
        }
        
        return maxLine;
    }
};
