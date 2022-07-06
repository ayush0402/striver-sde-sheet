// memoization

class Solution {
public:
    int f(string& text1, string&  text2, int i , int j, vector<vector<int>>&dp) {
        if (i < 0 || j < 0)return 0;
        if (dp[i][j] != -1)return dp[i][j];
        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + f(text1, text2, i - 1, j - 1, dp);
        }
        else {
            return dp[i][j] = max(f(text1, text2, i - 1, j, dp), f(text1, text2, i, j - 1, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return f(text1, text2, text1.size() - 1, text2.size() - 1, dp);
    }
};

// tabulation

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
        bool found = false;
        for (int i = 0; i < text1.size(); i++) {
            if (text1[i] == text2[0])found = true;
            if (found)dp[i][0] = 1;
        }
        found = false;
        for (int j = 0; j < text2.size(); j++) {
            if (text1[0] == text2[j])found = true;
            if (found)dp[0][j] = 1;
        }
        for (int i = 1; i < text1.size(); i++) {
            for (int j = 1; j < text2.size(); j++) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size() - 1][text2.size() - 1];
    }
};
