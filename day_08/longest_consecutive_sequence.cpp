class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> st;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (st.find(nums[i] - 1) == st.end()) {
                int cn = nums[i];
                int len = 0;
                while (st.find(cn) != st.end()) {
                    len++;
                    cn++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
