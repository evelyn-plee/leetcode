class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        int lr = matrix.size();
        int lc = matrix[0].size();
        int zero_row = -1;
        for (int i = 0; i < lr; ++i) {
            if (zero_row != -1) break;
            for (int j = 0; j < lc; ++j) {
                if (matrix[i][j] == 0) {
                    zero_row = i;
                    break;
                }
            }
        }
        if (zero_row == -1) return;
        
        for (int i = zero_row + 1; i < lr; ++i) {
            bool set_zero = false;
            for (int j = 0; j < lc; ++j) {
                if (matrix[i][j] == 0) {
                    set_zero = true;
                    matrix[zero_row][j] = 0;
                }
            }
            if (set_zero)
                for (int j = 0; j < lc; ++j) 
                    matrix[i][j] = 0;
        }
        for (int j = 0; j < lc; ++j) {
            if (matrix[zero_row][j] == 0)
                for (int i = 0; i < lr; ++i)
                    matrix[i][j] = 0;
        }
        for (int j = 0; j < lc; ++j)
            matrix[zero_row][j] = 0;
        
    }
};
