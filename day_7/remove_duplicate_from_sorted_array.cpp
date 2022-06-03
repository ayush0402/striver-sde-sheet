class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; int j = 1;
        while (i < nums.size() && j < nums.size()) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i + 1;
    }
};