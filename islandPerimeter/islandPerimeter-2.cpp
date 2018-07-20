#include <iostream>

class Solution{
public:
    int islandPerimeter(vector<vector<int>>& grid){
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), int res = 0;
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]==0) continue;
                res += 4;
                if(i > 0 && grid[i-1][j] == 1) res-=2;
                if(j > 0 && grid[i][j-1] == 1) res-=2;
            }
        }
        return res;
    }
};