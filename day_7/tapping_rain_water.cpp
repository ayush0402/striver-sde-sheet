class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height[height.size() - 1];
        int maxx = INT_MIN;
        int maxindex = 0;
        for (int i = 0; i < height.size(); i++) {
            if (maxx < height[i]) {
                maxx = height[i];
                maxindex = i;
            }
        }
        for (int i = 1; i < maxindex; i++) {
            left = max(left, height[i - 1]);
            ans += max(0, left - height[i]);
        }

        for (int i = height.size() - 2; i > maxindex; i--) {
            right = max(right, height[i + 1]);
            ans += max(0, right - height[i]);
        }

        return ans;
    }
};