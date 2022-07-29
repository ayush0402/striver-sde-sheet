class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn = prices[0];
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] - minn > maxprofit) {
                maxprofit = prices[i] - minn;
            }
            if (minn > prices[i]) {
                minn = prices[i];
            }
        }
        return maxprofit;
    }
};
