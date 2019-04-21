class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid){
        int orangeCnt = 0, day = -1, r = grid.size(), c = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dir={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j]>0) orangeCnt++;
                if(grid[i][j]==2) q.push({i, j});
            }
        }
        while(!q.empty()) {
            day++;
            int size=q.size();
            for(int k=0;k<size;k++) {
                pair<int, int> cur = q.front(); q.pop();
                orangeCnt--;
                for(int i=0;i<4;i++) {
                    int x= cur.first + dir[i][0], y = cur.second + dir[i][1];
                    if( x >= r || x < 0 || y >= c || y < 0 || grid[x][y] != 1 ) continue;
                    grid[x][y]=2;
                    q.push({x, y});
                }
            }
        }
        return orangeCnt==0 ? max(0, day) : -1;
    }
};
