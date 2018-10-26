class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> col(m,0),row(n,0);
        for(int i = 0 ; i <n;i++){
            for(int j=0;j<m;j++){
                row[i] = max(grid[i][j],row[i]);
                col[j] = max(grid[i][j],col[j]);
            }
        }
        long long total = 0;
        for(int i = 0 ; i <n;i++)
            for(int j=0;j<m;j++)
                total+= min(col[j],row[i]) - grid[i][j];
        return total;  
    }
};
