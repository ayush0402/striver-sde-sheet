class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mep;
        for (int i = 0; i < nums.size(); i++) {
            mep[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto [x, y] : mep) {
            pq.push({y, x});
            if (pq.size() > k)pq.pop();
        }
        vector <int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
