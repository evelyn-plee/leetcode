class Solution {
private:
    vector<bool> visited;
    vector<vector<int>> skip;
    
public:
    int dfs(int m, int n, int len, int num) {
        int cnt = 0;
        
        // current length of numbers swipped equal or larger than m
        // add counter
        if (len >= m) {
            cnt += 1;
        }
        
        len += 1;
        
        // if current length is out of bound, return from dfs with cnt
        if (len > n) {
            return cnt;
        }
        
        // first set current number as visited
        visited[num] = true;
        
        // go over all 9 numbers, do dfs
        for (int i = 1; i <= 9; i++) {
            
            // if the destination is not visited or it doens't contain skip number with current number
            // or the skip number is visited
            if (visited[i] == false && (skip[num][i] == 0 || visited[skip[num][i]] == true)) {
                cnt += dfs(m, n, len, i);
            }
        }
        
        // then set back current number as non-visited
        visited[num] = false;
        
        return cnt;
    }
    
    
    int numberOfPatterns(int m, int n) {
        int res = 0;
        visited.resize(10, false);
        skip.resize(10, vector<int>(10, 0));
        
        skip[1][3] = skip[3][1] = 2;
        skip[4][6] = skip[6][4] = 5;
        skip[7][9] = skip[9][7] = 8;
        skip[1][7] = skip[7][1] = 4;
        skip[2][8] = skip[8][2] = 5;
        skip[3][9] = skip[9][3] = 6;
        skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = 5;
        res += dfs(m, n, 1, 1) * 4;
        res += dfs(m, n, 1, 2) * 4;
        res += dfs(m, n, 1, 5);
        return res;
    }
};
