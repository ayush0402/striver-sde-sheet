class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        bool allNeg = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                allNeg = false; break;
            }
        }

        if (allNeg) {
            ans = nums[0];
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > ans)ans = nums[i];
            }

        }
        else {
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                ans = max(sum, ans);
                if (sum < 0)sum = 0;
            }
        }
        return ans;
    }
};
