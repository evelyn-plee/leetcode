class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size();
        int n = m ? M[0].size() : 0;
        vector<vector<int>> res = M, dirs{{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int cnt = M[i][j], totalPoint = 1;
                for(auto d : dirs){
                    int x = i + d[0], y = j + d[1];
                    if(x < 0 || x >= m || y < 0 || y >= n) continue;
                    cnt += M[x][y];
                    ++totalPoint;
                }
                res[i][j] = cnt/totalPoint;
            }
        }
        return res;
    }
};
