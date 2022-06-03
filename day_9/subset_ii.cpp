/**
 * In case of unique elements in the array, the default way of dealing with recursion problems
 * is used. i.e. making decision for each index if it has to be included in the resultant or not.
 * But in case the input array has duplicate occurences the output may have duplicate subsets too,
 * In that case the array should be first sorted and only the unique subsets should be included in
 * the answer. This can be done through going by the size of the resultant subset, i.e. for each
 * possible length of the subset a decision has to be made for each index checking that for that particular
 * index a call with same value has not been made yet. And then another call would be made under it
 * restricted to picking up the remaining indexes.
 *
 * Reference: https://www.youtube.com/watch?v=RIn3gOkbhQE
*/

class Solution {
public:
    void recur(vector <int>& nums, vector<vector<int>>& ans, vector<int>& temp, int n) {
        ans.push_back(temp);
        for (int i = n - 1; i >= 0; i--) {
            if (i != n - 1 && nums[i] == nums[i + 1])continue;
            temp.push_back(nums[i]);
            recur(nums, ans, temp, i);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector <int> temp;
        sort(nums.begin(), nums.end());
        recur(nums, ans, temp, nums.size());
        return ans;
    }
};
