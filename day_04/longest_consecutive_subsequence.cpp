class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> st;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        int longestStreak = 0;

        for (int i = 0; i < nums.size(); i++) {
            // previous element is not present, hence can't be a part of a longer subsequence
            if (st.find(nums[i] - 1) == st.end()) {
                int currentStreak = 0;
                int currentNumber = nums[i];
                while (st.find(currentNumber) != st.end()) {
                    currentStreak++;
                    currentNumber++;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;

    }
};
