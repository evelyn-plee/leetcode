class BFS_Solution{
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor){
        int originalColor = image[sr][sc];
        if(originalColor == newColor) return image;
        
        int r = image.length; int c = image[0].length;
        bool[][] visited = new boolean[r][c];
        int[][] dirs = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        image[sr][sc] = newColor;
        Queue<int[]> queue = new LinkedList<>();
        while(!queue.isEmpty()){
            int[] cur = queue.poll();
            visited[cur[0]][cur[1]] = true;
            for(int i = 0; i < 4; i++){
                int nr = cur[0] + dirs[i][0];
                int nc = cur[1] + dirs[i][1];
                if(nr < 0 || nc < 0 || nr >= r || nc >= r || image[nr][nc] != originalColor) continue;
                image[nr][nc] = newColor;
                queue.offer(new int[]{nr, nc})
            }
        }
        return image;
    }
}

class DFS_Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor){
        int originalColor = image[sr][sc];
        if(originalColor != newColor) dfs(image, sr, sc, originalColor, newColor);
        return image;
    }
    
    private void dfs(int[][] image, int r, int c, int color, int newColor){
        if(image[r][c] == color){
            image[r][c] = newColor;
            if(r >= 1) dfs(image, r-1, c, color, newColor);
            if(c >= 1) dfs(image, r, c-1, color, newColor);
            if(r+1 < image.length) dfs(image, r+1, c, color, newColor);
            if(c+1 < image[0].length) dfs(image, r, c+1, color, newColor);
         }
    }
}
