class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0; int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // is left half sorted
            if (nums[mid] >= nums[0]) {
                if (target <= nums[mid] && target >= nums[0]) {
                    hi = mid - 1;
                }
                else {
                    lo = mid + 1;
                }
            }
            else {
                if (target <= nums[nums.size() - 1] && target >= nums[mid]) {
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
        }
        return -1;
    }
};
