class Solution {
public:
    int vis[301][301];
    int rowsG, colsG;

    bool isValid(int x, int y) {
        if (x >= rowsG || y >= colsG || x < 0 || y < 0)return false;
        if (vis[x][y])return false;
        return true;
    }

    void dfs(int x, int y, vector<vector<char>>& grid) {
        vis[x][y] = 1;

        if (isValid(x - 1, y) && grid[x - 1][y] == '1')dfs(x - 1, y, grid);
        if (isValid(x + 1, y) && grid[x + 1][y] == '1')dfs(x + 1, y, grid);
        if (isValid(x, y + 1) && grid[x][y + 1] == '1')dfs(x, y + 1, grid);
        if (isValid(x, y - 1) && grid[x][y - 1] == '1')dfs(x, y - 1, grid);

    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        rowsG = rows;
        colsG = cols;

        int islands = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    islands++;
                    dfs(i, j, grid);
                }
            }
        }
        return islands;
    }
};
