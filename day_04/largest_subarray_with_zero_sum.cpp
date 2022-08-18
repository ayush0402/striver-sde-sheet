class Solution {
public:
    int maxLen(vector<int>&A, int n)
    {
        unordered_map <int, int> preMap;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            if (sum == 0) {
                ans = max(ans, i + 1);
            }
            if (preMap.find(sum) != preMap.end()) {
                ans = max(ans, i - preMap[sum]);
            }
            else {
                preMap.insert({sum, i});
            }
        }
        return ans;
    }
};
