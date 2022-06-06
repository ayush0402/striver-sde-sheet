// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>& m, vector<vector<int>>& vis) {
        int n = m.size();
        if (i < n && j < n && i >= 0 && j >= 0 && vis[i][j] == 0 && m[i][j] == 1) {
            return true;
        }
        return false;
    }
    void recur(vector<vector<int>>& m, vector<vector<int>>& vis, int n, string& temp, int i, int j, vector<string>& ans) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(temp);
            return;
        }

        if (i >= n || j >= n || i < 0 || j < 0)return;

        if (isValid(i + 1, j, m, vis)) {
            vis[i + 1][j] = 1;
            temp.push_back('D');
            recur(m, vis, n, temp, i + 1, j, ans);
            vis[i + 1][j] = 0;
            temp.pop_back();
        }
        if (isValid(i, j + 1, m, vis)) {
            vis[i][j + 1] = 1;
            temp.push_back('R');
            recur(m, vis, n, temp, i, j + 1, ans);
            vis[i][j + 1] = 0;
            temp.pop_back();
        }
        if (isValid(i - 1, j, m, vis)) {
            vis[i - 1][j] = 1;
            temp.push_back('U');
            recur(m, vis, n, temp, i - 1, j, ans);
            vis[i - 1][j] = 0;
            temp.pop_back();
        }
        if (isValid(i, j - 1, m, vis)) {
            vis[i][j - 1] = 1;
            temp.push_back('L');
            recur(m, vis, n, temp, i, j - 1, ans);
            vis[i][j - 1] = 0;
            temp.pop_back();
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string temp = "";
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        if (m[0][0] == 0) {
            return ans;
        }
        recur(m, vis, n, temp, 0, 0, ans);

        return ans;
    }
};




// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
