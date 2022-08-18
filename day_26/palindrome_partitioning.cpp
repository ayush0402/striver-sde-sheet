//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

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

    int recur(string s, int currindex, int startindex, vector<vector<int>>& dp) {
        if (dp[startindex][currindex] != -1)return dp[startindex][currindex];
        if (currindex == s.size() - 1) {
            if (isPalindrome(s.substr(startindex, currindex - startindex + 1))) {
                return dp[startindex][currindex] = 0;
            }
            return dp[startindex][currindex] = 1e5;
        }

        int split = 1e5;

        if (isPalindrome(s.substr(startindex, currindex - startindex + 1))) {
            split = 1 + recur(s, currindex + 1, currindex + 1, dp);
        }
        return dp[startindex][currindex] = min(split, recur(s, currindex + 1, startindex, dp));
    }
    int palindromicPartition(string str)
    {
        vector <vector<int>> dp(str.size(), vector<int>(str.size(), -1));
        return recur(str, 0, 0, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}
// } Driver Code Ends
