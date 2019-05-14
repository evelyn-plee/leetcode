class DFS_Solution{
    int h, w;
    int[][] step = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    public int numEnclaves(int[][] A){
        h = A.length; w = A[0].length;
        for(int i = 0; i < w; i++){
            if(A[0][i] == 1) dfs(A, 0, i);
            if(A[h-1][i] == 1) dfs(A, h-1, i);
        }
        for(int i = 1; i < h-1; i++){
            if(A[i][0] == 1) dfs(A, i, 0);
            if(A[i][w-1] == 1) dfs(A, i, w-1);
        }
        int count = 0;
        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){
                count += (A[j][i] == 1 ? 1 : 0);
            }
        }
        return count;
    }
    
    private void dfs(int[][] A, int y, int x){
        A[y][x] = 0;
        for(int i = 0; i < 4; i++){
            int yy = y + step[i][0];
            int xx = x + step[i][1];
            if(valid(xx, yy) && A[yy][xx] == 1) dfs(A, yy, xx);
        }
    }
    
    private boolean valid(int x, int y){
        return x >= 0 && y >= 0 && x < w && y < h;
    }
}
