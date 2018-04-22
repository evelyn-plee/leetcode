class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> a(m, vector<bool> (n,false));
        vector<vector<bool>> b(m, vector<bool> (n,false));
        vector<vector<bool>> c(m, vector<bool> (n,false));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == '.') continue;
                int k = board[i][j] - '1';

                int p = i/3*3 + j/3;
                if(a[i][k] || b[j][k] || c[p][k]) return false;
                else
                {
                    a[i][k] = true;
                    b[j][k] = true;
                    c[p][k] = true;
                }
            }
        }
        return true;
    }
};
