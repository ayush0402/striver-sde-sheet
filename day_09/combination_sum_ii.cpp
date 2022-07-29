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

class Solution {
public:
    void recur(vector<int>& candidates, int target, int sum, int index, vector<int>& temp, vector<vector<int>>& ans) {
        if (target == sum) {
            ans.push_back(temp);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i != index && candidates[i - 1] == candidates[i])continue;
            if (candidates[i] + sum > target)continue;
            temp.push_back(candidates[i]);
            recur(candidates, target, sum + candidates[i], i + 1, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        recur(candidates, target, 0, 0, temp, ans);

        return ans;
    }
};