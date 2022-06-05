class Solution {
public:
    void recur(vector<int>& nums, vector<vector<int>>& ans, int index) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            recur(nums, ans, index + 1);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recur(nums, ans, 0);

        return ans;
    }
};
