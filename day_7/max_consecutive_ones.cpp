class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int anstemp = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                anstemp++;
                ans = max(ans, anstemp);
            }
            else anstemp = 0;
        }
        return ans;
    }
};
