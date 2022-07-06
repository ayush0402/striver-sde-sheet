// Gives TLE

class Solution {
public:
    int f(vector <int>& nums, vector<vector<int>>& dp, int i, int lastind) {
        if (i == nums.size()) {
            return 0;
        }
        if (lastind == nums.size() - 1) {
            if (dp[i][nums.size() - 1] != -1) return dp[i][nums.size() - 1];
            return dp[i][nums.size() - 1] = max(1 + f(nums, dp, i + 1, i), f(nums, dp, i + 1, lastind));
        }
        if (nums[lastind] < nums[i]) {
            return dp[i][lastind] = max(1 + f(nums, dp, i + 1, i), f(nums, dp, i + 1, lastind));
        }
        return dp[i][lastind] = f(nums, dp, i + 1, lastind);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return f(nums, dp, 0, nums.size() - 1);
    }
};
