class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> mep;
        vector <int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int tofind = target - nums[i];
            if (mep.find(tofind) != mep.end()) {
                ans.push_back(i);
                ans.push_back(mep[tofind]);
                break;
            }
            else {
                mep.insert({nums[i], i});
            }
        }
        return ans;
    }
};
