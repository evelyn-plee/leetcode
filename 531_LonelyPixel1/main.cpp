class Solution{
public:
    int findLonelyPixel(vector<vector<char>>& picture){
        int m = picture.size();
        if(m == 0) return 0;
        int n = picture[0].size();
        if(n == 0) return 0;
        
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                rows[i] += picture[i][j] == 'B';
                cols[i] += picture[i][j] == 'B';
            }
        }
        
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans += picture[i][j] == 'B' && rows[i] == 1 && cols[j] == 1;
            }
        }
        return ans;
    }
};
