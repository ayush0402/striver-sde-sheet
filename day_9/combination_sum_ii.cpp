class Solution {
public:
    void recur(vector<vector<int>>& ans, vector<int>& temp, int n , int target, int sum, vector<int>& candidates) {
        if (sum == target) {
            ans.push_back(temp);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i != n - 1 && candidates[i] == candidates[i + 1])continue;
            if (candidates[i] + sum <= target) {
                temp.push_back(candidates[i]);
                recur(ans, temp, i, target, sum + candidates[i], candidates);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector <vector<int>> ans;
        vector <int> temp;
        sort(candidates.begin(), candidates.end());
        recur(ans, temp, candidates.size(), target, 0, candidates);
        return ans;
    }
};
