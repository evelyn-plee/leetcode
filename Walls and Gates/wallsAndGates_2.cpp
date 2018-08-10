class Solution{
public:
    void wallsAndGates(vector<vector<int>> &rooms){
        queue<pair<int, int>> q;
        vector<vector<int>> dis{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        for(int i = 0; i < rooms.size(); i++){
            for(int j = 0; j < rooms[i].size(); j++){
                if(rooms[i][j] == 0) q.push({i,j});
            }
        }
        
        while(!q.empty()){
            int i = q.front().first, j = q.front().second; q.pop();
            for(int k = 0; k < dis.size(); k++){
                int x = i + dis[k][0], y = j + dis[k][1];
                if(x < 0 || x >= room.size() || y < 0 || y >= rooms[0].size() || rooms[x][y] < rooms[i][j] + 1) continue;
                rooms[x][y] = rooms[i][j] + 1;
                q.push({x, y});
            }
        }
    }
};
