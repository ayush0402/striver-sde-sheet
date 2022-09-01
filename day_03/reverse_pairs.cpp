class Solution {
public:
    void merge(vector<int>& nums, int lo, int mid, int hi, int& ans) {
        vector <int> temp;
        int i = lo; int j = mid + 1;

        for (int ii = lo; ii <= mid; ii++) {
            while (j <= hi && nums[ii] > (long long)2 * nums[j])ans += mid - ii + 1, j++;
        }
        j = mid + 1;
        while (i <= mid && j <= hi) {
            if (nums[i] > nums[j]) {
                temp.push_back(nums[j]);
                j++;
            }
            else {
                temp.push_back(nums[i]);
                i++;
            }
        }
        while (i <= mid)temp.push_back(nums[i]), i++;
        while (j <= hi)temp.push_back(nums[j]), j++;

        for (int k = 0; k < temp.size(); k++) {
            nums[k + lo] = temp[k];
        }
    }
    void mergeSort(vector<int>& nums, int lo, int hi, int& ans) {
        if (lo < hi) {
            int mid = (lo + hi) / 2;
            mergeSort(nums, lo, mid, ans);
            mergeSort(nums, mid + 1, hi, ans);
            merge(nums, lo, mid, hi, ans);
        }
    }
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        mergeSort(nums, 0, nums.size() - 1, ans);
        return ans;
    }
};
