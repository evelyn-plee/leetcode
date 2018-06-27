class Solution{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        vector<int> ret;
        if(matrix.empty() || matrix[0].empty()) return ret;
        
        int m = matrix.size(), n = matrix[0].size();
        int level = (min(m,n)+1)/2;
        
        for(int i = 0; i < level; i++){
            int lastRow = m-1-i;
            int lastCol = n-1-i;
            if(lastRow == i){
                for(int j = i; j <= lastCol; j++)
                    ret.push_back(matrix[i][j]);
            } else if(lastCol == i){
                for(int j = i; j <= lastRow; j++)
                    ret.push_back(matrix[j][i]);
            } else{
                 for(int j = i; j < lastCol; j++)
                    ret.push_back(matrix[i][j]);
                for(int j = i; j < lastRow; j++)
                    ret.push_back(matrix[j][lastCol]);
                for(int j = lastCol; j > i; j--)
                    ret.push_back(matrix[lastRow][j]);
                for(int j = lastRow; j > i; j--)
                    ret.push_back(matrix[j][i]);
            }
        }
        return ret;
    }
};
