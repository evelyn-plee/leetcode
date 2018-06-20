class Solution{
public:
  void setZeros(vector<vector<int>>& matrix){
    if (matrix.empty() or matrix[0].empty()) return;
    int n = matrix.size(), m = matrix[0].size();

    bool row0 = false;
    for(int j = 0; j < m; j++){
        if(matrix[0][j] == 0){
            row0 = true;
            break;
        }
    }

    for(int i = 1; i < n; i++){
        bool row = false;
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                row = true;
            }
            if(row) fill(matrix[i].begin(), matrix[i].end(), 0);
        }
    }

    for(int j = 1; j < m; j++){
        if(matrix[0][j] == 0){
            for(int i = 1; i < n; i++){
                matrix[i][j] = 0;
            }
        }
    }    

    if(row0) fill(matrix[0].begin(), matrix[0].end(), 0);
}
}
