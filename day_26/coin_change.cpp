class Solution {
public:
    int f(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {
        if (i < 0)return 1e5;
        if (amount == 0)return 0;
        if (dp[i][amount] != -1)return dp[i][amount];
        int pick = INT_MAX;
        if (amount - coins[i] >= 0)
            pick = 1 + f(coins, amount - coins[i], i, dp);
        int notpick = f(coins, amount, i - 1, dp);

        return dp[i][amount] = min(pick, notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector <vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int ans = f(coins, amount, coins.size() - 1, dp);
        if (ans == 1e5)return -1;
        else return ans;
    }
};
