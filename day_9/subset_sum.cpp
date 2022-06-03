//Recursive

class Solution {
public:
    void sumfunc(vector<int>& arr, int n, int sum, vector <int>& temp) {
        if (n == 0) {
            temp.push_back(sum);
            return;
        }
        sumfunc(arr, n - 1, sum, temp);
        sumfunc(arr, n - 1, sum + arr[n - 1], temp);

        return;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector <int> temp;
        sumfunc(arr, N, 0, temp);

        return temp;
    }
};

// Iterative

class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector <int> ans;
        int totalSubsets = 1 << N;
        for (int i = 0; i < totalSubsets; i++) {
            int sum = 0;
            for (int j = 0; j < N; j++) {
                int mask = 1 << j;
                if ((i & mask) != 0) {
                    sum += arr[j];
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
