// memoization using 3D Array

class Solution {
public:
    int f(vector<string>& strs, int m, int n, int i, vector<vector<vector<int>>>& dp) {
        if (i < 0)return 0;
        if (dp[i][m][n] != -1)return dp[i][m][n];
        int one = 0; int zero = 0;
        for (int k = 0; k < strs[i].size(); k++) {
            if (strs[i][k] == '1')one++;
            else zero++;
        }
        int take = 0;
        if (m >= zero && n >= one)
            take = 1 + f(strs, m - zero, n - one, i - 1, dp);
        int nottake = f(strs, m, n, i - 1, dp);

        return dp[i][m][n] = max(take, nottake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return f(strs, m, n, strs.size() - 1, dp);
    }
};

// tabular
