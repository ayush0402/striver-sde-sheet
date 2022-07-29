// TODO : Figure out the time complexity.

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0; int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j])return false;
            i++; j--;
        }
        return true;
    }
    void recur(vector<vector<string>>& ans, string s, int start, int end, vector<string>& temp, int size) {
        if (size == s.size()) {
            ans.push_back(temp);
            return;
        }
        if (end > s.size() - 1) {
            return;
        }
        if (isPalindrome(s.substr(start, end - start + 1))) {
            temp.push_back(s.substr(start, end - start + 1));
            recur(ans, s, end + 1, end + 1, temp, size + (end - start + 1));
            temp.pop_back();
        }
        recur(ans, s, start, end + 1, temp, size);
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        recur(ans, s, 0, 0, temp, 0);
        return ans;
    }
};
