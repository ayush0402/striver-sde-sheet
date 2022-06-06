class Solution {
public:
    bool isValid(vector<string>& board, int row, int col, int n) {
        for (int i = 0; i < n; i++) {
            if (board[row][i] == 'Q' || board[i][col] == 'Q')return false;
        }
        int i = row; int j = col;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')return false;
            i--; j--;
        }
        i = row; j = col;
        while (i < n && j < n) {
            if (board[i][j] == 'Q')return false;
            i++; j++;
        }
        i = row; j = col;
        while (i < n && j >= 0) {
            if (board[i][j] == 'Q')return false;
            i++; j--;
        }
        i = row; j = col;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q')return false;
            i--; j++;
        }

        return true;
    }
    void recur(vector<string>& board, int queens, int row, int n, vector<vector<string>>& ans) {

        if (queens == n) {
            ans.push_back(board);
            return;
        }
        if (row >= n) {
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(board, row, i, n)) {
                board[row][i] = 'Q';
                recur(board, queens + 1, row + 1, n, ans);
                board[row][i] = '.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string rowstr = "";
        for (int i = 0; i < n; i++)rowstr.push_back('.');
        vector<string> board(n, rowstr);
        recur(board, 0, 0, n, ans);
        return ans;
    }
};
