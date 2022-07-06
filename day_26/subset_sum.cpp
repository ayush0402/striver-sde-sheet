// memoization

class Solution {
public:
    bool sum1(vector <int>& nums, int i, int s, int tempsum, vector<vector<int>>& dp) {
        if (tempsum == s)return true;
        if (i < 0)return false;
        if (dp[i][tempsum] != -1)return dp[i][tempsum];
        return dp[i][tempsum] = (sum1(nums, i - 1, s, tempsum + nums[i], dp) || sum1(nums, i - 1, s, tempsum, dp));
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) {
            return false;
        }
        vector <vector<int>> dp(nums.size(), vector<int>(sum, -1));
        return sum1(nums, nums.size() - 1, sum / 2, 0, dp);
    }
};

// -- alternative memoized solution

class Solution {
public:
    bool f(vector<int>& nums, int sum, int i, vector<vector<int>>& dp) {
        if (i < 0) {
            return false;
        }
        if (sum == 0)return true;
        if (dp[i][sum] != -1)return dp[i][sum];
        bool take = false;
        if (sum >= nums[i])take = f(nums, sum - nums[i], i - 1, dp);
        bool nottake = f(nums, sum, i - 1, dp);

        return dp[i][sum] = (take || nottake);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1)return false;

        vector<vector<int>> dp(nums.size(), vector<int>((sum / 2) + 1, -1));
        return f(nums, sum / 2, nums.size() - 1, dp);
    }
};

// tabular
