class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                // now this is two sum II
                int lo = j + 1; int hi = nums.size() - 1;
                while (lo < hi) {
                    if ((long long)nums[i] + nums[j] + nums[lo] + nums[hi] < (long long)target) {
                        lo++;
                        while (lo < nums.size() && nums[lo] == nums[lo - 1])lo++;
                    }
                    else if ((long long)nums[i] + nums[j] + nums[lo] + nums[hi] > (long long)target) {
                        hi--;
                        while (hi >= 0 && nums[hi] == nums[hi + 1])hi--;
                    }
                    else {
                        ans.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        lo++;
                        while (lo < nums.size() && nums[lo] == nums[lo - 1])lo++;
                    }
                }
                while (j + 1 < nums.size() && nums[j + 1] == nums[j])j++;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])i++;
        }
        return ans;
    }
};
