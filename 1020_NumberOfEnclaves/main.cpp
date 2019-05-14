class DFS_Solution{
public:
    int numEnclaves(vector<vector<int>>& A){
        h = A.size(), w = A[0].size();
        for(int i = 0; i < w; i++){
            if(A[0][i]) dfs(A, 0, i);
            if(A[h-1][i]) dfs(A, h-1, i);
        }
        for(int i = 1; i < h-1; i++){
            if(A[i][0]) dfs(A, i, 0);
            if(A[i][w-1]) dfs(A, i, w-1);
        }
        int count = 0;
        for(int x = 0; x < w; x++){
            for(int y = 0; y < h; y++){
                count += A[y][x];
            }
        }
        return count;
    }
private:
    int h, w;
    int step[4][2] = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1}
    };
    void dfs(vector<vector<int>>& A, int y, int x){
        A[y][x] = 0;
        for(int i = 0; i < 4; i++){
            int yy = y + step[i][0];
            int xx = x + step[i][1];
            if(valid(xx, yy) && A[yy][xx]) dfs(A, yy, xx);
        }
    }

    bool valid(int x, int y){
        return x >= 0 && x < w && y >= 0 && y < h;
    }
};
