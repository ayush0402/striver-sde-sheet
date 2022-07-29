class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = ((matrix.size()) * (matrix[0].size())) - 1;

        int s = matrix[0].size();

        int mid = (l + r) / 2;


        while (l <= r) {
            mid = (l + r) / 2;
            int row = mid / s;
            int col = mid % s;

            if (matrix[row][col] == target) return true;

            if (matrix[row][col] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }

};
