class BFS_Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        int r = image.size(), c = image[0].size(), originalColor =  image[sr][sc];
        
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;
        
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int nr = cur.first + dirs[i][0], nc = cur.second + dirs[i][1];
                if( nr >= 0 && nc >= 0 && nr < r && nc < c && image[nr][nc] == originalColor){
                    image[nr][nc] = newColor;
                    q.push({nr, nc});
                }

            }
        }
        return image;
    }
};


class DFS_Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        int originalColor =  image[sr][sc];
        if(originalColor != newColor) dfs(image, sr, sc, originalColor, newColor);
        return image;
    }
    
private: 
    void dfs(vector<vector<int>>& image, int r, int c, int color, int newColor){
        
        if(image[r][c] == color){
            image[r][c] = newColor;
            if(r >= 1) dfs(image, r-1, c, color, newColor);
            if(c >= 1) dfs(image, r, c-1, color, newColor);
            if(r+1 < image.size()) dfs(image, r+1, c, color, newColor);
            if(c+1 < image[0].size()) dfs(image, r, c+1, color, newColor);
        }
    }
};
