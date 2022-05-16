class Solution
{
public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector <pair<double, int>> v;
        for (int i = 0; i < n; i++) {
            int val = arr[i].value;
            int wt = arr[i].weight;
            double ratio = (double)val / wt;
            v.push_back({ratio, wt});
        }
        sort(v.begin(), v.end());
        double ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (v[i].second <= W) {
                ans += (double)v[i].second * v[i].first;
                W -= v[i].second;
            }
            else {
                ans += (double)W * v[i].first;
                break;
            }

        }
        return ans;
    }

};
