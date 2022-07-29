// Most Optimal Solution

class Solution {
public:
    string getPermutation(int n, int k) {
        vector <char> v = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        string ans = "";
        int fact = 1;
        for (int i = 1; i < n; i++) {
            fact = fact * i;
        }
        k--;
        int factdiv = n - 1;

        while (ans.size() < n) {
            int temp = k / fact;
            k = k % fact;
            ans.push_back(v[temp]);
            v.erase(v.begin() + temp);
            if (factdiv == 0)factdiv = 1;
            fact = fact / factdiv;
            factdiv--;
        }
        return ans;
    }
};

// TODO : Optimise recursion method. Gives TLE.

class Solution {
public:
    void recur(string& v, vector <string>& ans, int index, int n) {
        if (index == n) {
            ans.push_back(v);
        }
        for (int i = index; i < n; i++) {
            swap(v[index], v[i]);
            recur(v, ans, index + 1, n);
            swap(v[index], v[i]);
        }
    }
    string getPermutation(int n, int k) {
        string v;
        for (int i = 1; i <= n; i++) {
            v.push_back(i + '0');
        }
        vector <string> ans;
        recur(v, ans, 0, n);
        sort(ans.begin(), ans.end());
        return ans[k - 1];
    }
};
