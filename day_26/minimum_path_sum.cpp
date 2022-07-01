// memoization

class Solution {
public:
    int f(vector<vector<int>>& grid, int i, int j, vector<vector<int>>&dp) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1)return 0;
        if (i >= grid.size() || j >= grid[0].size())return 1e5;
        if (dp[i][j] != -1)return dp[i][j];

        int right = 1e5;
        if (j + 1 < grid[0].size())
            right = grid[i][j + 1] + f(grid, i, j + 1, dp);
        int down = 1e5;
        if (i + 1 < grid.size())
            down = grid[i + 1][j] + f(grid, i + 1, j, dp);

        return dp[i][j] = min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return grid[0][0] + f(grid, 0, 0, dp);
    }
};

// tabular

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[grid.size() - 1][grid[0].size() - 1] = grid[grid.size() - 1][grid[0].size() - 1];

        for (int j = grid[0].size() - 2; j >= 0; j--)
        {
            dp[grid.size() - 1][j] = grid[grid.size() - 1][j] + dp[grid.size() - 1][j + 1];
        }
        for (int i = grid.size() - 2; i >= 0; i--)
        {
            dp[i][grid[0].size() - 1] = grid[i][grid[0].size() - 1] + dp[i + 1][grid[0].size() - 1];
        }

        for (int i = grid.size() - 2; i >= 0; i--) {
            for (int j = grid[0].size() - 2; j >= 0; j--) {
                int right = grid[i][j] + dp[i][j + 1];
                int down = grid[i][j] + dp[i + 1][j];

                dp[i][j] = min(right, down);
            }
        }

        return dp[0][0];
    }
};
