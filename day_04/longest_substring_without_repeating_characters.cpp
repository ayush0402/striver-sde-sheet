// Brute:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for (int i  = 0; i < s.size(); i++) {
            unordered_set <int> st;
            for (int j = i; j < s.size(); j++) {
                if (st.find(s[j]) != st.end()) {
                    break;
                }
                ans = max(ans, j - i + 1);
                st.insert(s[j]);
            }
        }
        return ans;
    }
};

// Better:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0; int r = 0;
        unordered_set <int> st;
        while (r < s.size()) {
            while (st.find(s[r]) != st.end()) {
                st.erase(s[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
            st.insert(s[r]);
            r++;
        }
        return ans;
    }
};

// Optimal:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0; int r = 0;
        unordered_map <char, int> mep;
        while (r < s.size()) {
            if (mep.find(s[r]) != mep.end()) {
                l = max(l, mep[s[r]] + 1);
            }
            ans = max(ans, r - l + 1);
            mep[s[r]] = r;
            r++;
        }
        return ans;
    }
};
