class Solution {
    public int findLonelyPixel(char[][] picture) {
        int m = picture.length;
        if(m == 0) return 0;
        int n = picture[0].length;
        if(n == 0) return 0;
        
        int[] rows = new int[m];
        int[] cols = new int[n];
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                rows[i] += picture[i][j] == 'B' ? 1 : 0;
                cols[j] += picture[i][j] == 'B' ? 1 : 0;
            }
        }
        
        int lonely = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n && rows[i] > 0; j++) {
                lonely += (picture[i][j] == 'B' && rows[i] == 1 && cols[j] == 1) ? 1 : 0;
            }
        }

        return lonely;     
    }
}
