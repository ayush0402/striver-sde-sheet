class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector<int>> ans;
        /*
            Idea is to sort the array and run a loop to find
            the first number of the triplet, then for the next
            two numbers the problem reduces to the Two Sum - II.

            To make sure duplicate triplets are not included in the answer
            increase the indexes till the number is not equal to the last number.
        */
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int x = nums[i];
            // reduced to Two-Sum - II
            int l = i + 1; int r = nums.size() - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] < 0) {
                    l++;
                    // below step is not necessary as it us automatically taken care of
                    // while (nums[l] == nums[l - 1] && l < r)l++;
                }
                else if (nums[i] + nums[l] + nums[r] > 0) {
                    r--;
                    // below step is not necessary as it us automatically taken care of
                    // while (nums[r] == nums[r + 1] && l < r)r--;
                }
                else {
                    vector <int> temp = {x, nums[l], nums[r]};
                    ans.push_back(temp);

                    l++;
                    while (nums[l] == nums[l - 1] && l < r)l++;

                    /*  OR reduce r
                        r--;
                        while (nums[r] == nums[r+1] && l<r)r--;
                     */
                }
            }

        }
        return ans;
    }
};
