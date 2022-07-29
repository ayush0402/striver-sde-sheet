/** Efficient two-pointer 1 pass TC: O(n) SC: O(1) solution
 *  youtube.com/watch?v=ZI2z5pq0TqA
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;

        int l = 0; int r = height.size() - 1;
        int left_max = height[l]; int right_max = height[r];

        while (l < r) {
            if (left_max < right_max) {
                l++;
                left_max = max(left_max, height[l]);
                ans += max(0, left_max - height[l]);
            }
            else {
                r--;
                right_max = max(right_max, height[r]);
                ans += max(0, right_max - height[r]);
            }
        }
        return ans;
    }
};

// Alternative global maximum 2 pass TC: O(n) SC: O(1) solution

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