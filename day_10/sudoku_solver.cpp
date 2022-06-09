class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size();  i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, i, j, ch)) {
                            board[i][j] = ch;
                            if (solve(board))return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board, int i, int j, char ch) {
        for (int k = 0; k < board.size(); k++) {
            if (board[i][k] == ch || board[k][j] == ch)return false;
        }
        int starti = 3 * (i / 3);
        int startj = 3 * (j / 3);
        for (int l = starti; l < starti + 3; l++) {
            for (int r = startj; r < startj + 3; r++) {
                if (board[l][r] == ch)return false;
            }
        }
        return true;
    }


};
