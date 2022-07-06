/**
 * Reference: https://leetcode.com/problems/maximum-product-subarray/discuss/1609493/C%2B%2B-Simple-Solution-w-Explanation-or-Optimization-from-Brute-Force-to-DP
 *
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxx = nums[0]; int minn = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int maxxtemp = maxx; int minntemp = minn;
            maxx = max(nums[i], max(nums[i] * maxxtemp, nums[i] * minntemp));
            minn = min(nums[i], min(nums[i] * maxxtemp, nums[i] * minntemp));
            ans = max(maxx, ans);
        }
        return ans;
    }
};
