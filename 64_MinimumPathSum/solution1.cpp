//DP O(mn), O(1)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i == 0 && j == 0) continue;
                if(i == 0) grid[i][j] += grid[i][j-1];
                else if(j == 0) grid[i][j] += grid[i-1][j];
                else grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
            }
        }
        return grid[m-1][n-1];
    }
};

// Recursion with memo
// O(mn), O(mn)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        s_ = vector<vector<int>>(m, vector<int>(n, 0));
       
        return calculatePathSum(grid, n-1, m-1, n, m);
    }
private:
    vector<vector<int>> s_;
    
    int calculatePathSum(vector<vector<int>>& grid, int x, int y, int n, int m){
        if(x == 0 && y == 0) return grid[y][x];
        if(x < 0 || y < 0) return INT_MAX;
        if(s_[y][x] > 0) return s_[y][x];
        int ans = grid[y][x] + min(calculatePathSum(grid, x-1, y, n, m), calculatePathSum(grid, x, y-1, n, m));
        return s_[y][x] = ans;
    }
};
