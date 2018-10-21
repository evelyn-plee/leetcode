// dfs + backtracking
// O(4^l * mn) traverse the whole matrix, and l = len(word)
// O(mn + l)

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        if(board.size()==0) return false;
        m = board.size();
        n = board[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(search(board, word, 0, i, j)) return true;
        return false;
    }
    
   
private:
    int m, n;
     bool search(vector<vector<char>> &board, 
             const string& word, int d, int x, int y) {
        if(x<0 || x==n || y<0 || y==m || word[d] != board[y][x]) 
            return false;
        
        // Found the last char of the word
        if(d==word.length()-1)
            return true;
        
        char cur = board[y][x];
        board[y][x] = 0; 
        bool found = search(board, word, d+1, x+1, y)
                  || search(board, word, d+1, x-1, y)
                  || search(board, word, d+1, x, y+1)
                  || search(board, word, d+1, x, y-1);
        board[y][x] = cur;
        return found;
    }
};
