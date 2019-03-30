class Solution{
public:
    int slidingPuzzle(vector<vector<int>> &board){
        
        vector<vector<int>> target = {{1,2,3}, {4,5,0}};
        map<vector<vector<int>>, int> dist;
        
        queue<vector<vector<int>>> q;
        q.push(board);
        dist[board] = 0;
        
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        
        while(!q.empty()){
            vector<vector<int>> tmp = q.front(); q.pop();
            if(tmp == target) return dist[tmp];
            
            // find 0 position
            for(int c = 0; c < 3; c++){
                for(int r = 0; r < 2; r++){
                    if(tmp[r][c] == 0){
                        // Rotation 0 with neighbours;
                        int nR = r + dy[k], nC = c + dx[k];
                        if(nR < 0 || nR > 1 || nC < 0 || nC > 2) continue;
                        vector<vector<int>> newTmp = tmp;
                        swap(newTmp[r][c], newTmp[nR][nC]);
                        if(dist.count(newTmp)) dist[newTmp] = min(dist[newTmp], dist[tmp] + 1);
                        else{
                            q.push(newTmp);
                            dist[newTmp] = dist[tmp] + 1;
                        } 
                    }
                }
            }
        }
        return -1;
    }
};
