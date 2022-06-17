class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0; int hi = nums.size() - 1;
        int mid = (lo + hi) / 2;

        while (lo <= hi) {
            mid = (lo + hi) / 2;
            int toright = nums.size() - mid - 1;
            if (mid > 0 && nums[mid] == nums[mid - 1]) {
                if (toright % 2 == 0) hi = mid - 1;
                else lo = mid + 1;
            }
            else if (mid < nums.size() - 1 && nums[mid] == nums[mid + 1]) {
                if (toright % 2 == 0)lo = mid + 1;
                else hi = mid - 1;
            }
            else {
                return nums[mid];
            }
        }
        return nums[mid];
    }
};
