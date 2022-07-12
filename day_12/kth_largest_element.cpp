class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset <int> st;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
            if (st.size() > k)st.erase(st.begin());
        }
        return *st.begin();
    }
};
