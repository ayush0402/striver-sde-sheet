class Solution {
public:
    void recur(vector<int>& candidates, int target, vector <int>& temp, vector<vector<int>>& ans, int n, int sum) {
        if (n == 0) {
            if (sum == target)
                ans.push_back(temp);
            return;
        }
        if (candidates[n - 1] + sum <= target) {
            temp.push_back(candidates[n - 1]);
            recur(candidates, target, temp, ans, n, sum + candidates[n - 1]);
            temp.pop_back();
        }
        recur(candidates, target, temp, ans, n - 1, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector <int> temp;
        recur(candidates, target, temp, ans, candidates.size(), 0);
        return ans;
    }
};
