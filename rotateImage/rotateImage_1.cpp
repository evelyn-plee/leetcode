class Solution{
public:
  void rotate(vector<vector<int>>& matrix){
    int a = 0;
    int b = matrix.size() - 1;
    while(a < b){
      for(int i = 0; i<b-a; i++){
        temp = matrix[a][a+i];
        matrix[a][a+i] = matrix[b-i][a];
        matrix[b-i][a] = matrix[b][b-i];
        matrix[b][b-i] = matrix[a+i][b];
        matrix[a+i][b] = temp;
      }
      a++;
      b--;
    }
  }
};
