// Two-pass solution

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector <int> nse(n);
        vector <int> pse(n);
        stack <int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) pse[i] = st.top();
            else pse[i] = -1;
            st.push(i);
        }

        while (!st.empty())st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty())nse[i] = st.top();
            else nse[i] = n;
            st.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int left = pse[i] + 1;
            int right = nse[i] - 1;
            int area = (right - left + 1) * heights[i];

            res = max(res, area);
        }
        return res;
    }
};

// one-pass solution
// #TODO : Do one-pass solution.
