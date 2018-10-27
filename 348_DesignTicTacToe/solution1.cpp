class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n): total(n), rows(n), cols(n), diagonal(0), antiDiagonal(0){}
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int add = player == 1 ? 1 : -1;
        rows[row] += add;
        cols[col] += add;
        diagonal += row == col ? add : 0;
        antiDiagonal += row == total - col - 1 ? add : 0;
        if(abs(rows[row]) == total || abs(cols[col]) == total || abs(diagonal) == total || abs(antiDiagonal) == total) return player;
        return 0;
    }
private:
    vector<int> rows, cols;
    int diagonal, antiDiagonal;
    int total;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
