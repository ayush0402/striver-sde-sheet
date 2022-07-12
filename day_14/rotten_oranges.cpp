class Solution {
public:
    // direction vectors to find adjacent coordinates.
    vector <int> dx = { -1, 0, 1, 0};
    vector <int> dy = {0, 1, 0, -1};

    // Function to check if the cell is inside the grid and contains a fresh orange.
    bool isValid(int x, int y, vector<vector<int>>& grid) {
        if (x >= grid.size() || y >= grid[0].size() || x < 0 || y < 0)return false;
        if (grid[x][y] != 1)return false;
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        // Variables to keep the count of fresh and total number of oranges.
        int fresh = 0;
        int total = 0;
        queue <pair<int, int>> rotten;

        // Initialising the queue with rotten oranges at time = 0 and counting oranges.
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)fresh++, total++;
                else if (grid[i][j] == 2) {
                    rotten.push({i, j});
                    total++;
                }
            }
        }

        // If the grid has no fresh oranges, return 0.
        if (fresh == 0) {
            return 0;
        }
        // If the grid has no rotten oranges, return -1.
        if (total == fresh) {
            return -1;
        }

        int ans = 0;
        // Traversing the grid with standard BFS algorithm.
        // Checking for adjacent coordinates of each rotten orange till the queue is not empty.
        while (!rotten.empty()) {
            // Increasing the minutes count.
            ans++;
            /**
             * Each minute sz number of rotten oranges will be checked for adjacent fresh ones.
             * sz being the number of coordinates currently in the queue.
            */
            int sz = rotten.size();
            while (sz--) {
                int nodex = rotten.front().first;
                int nodey = rotten.front().second;
                rotten.pop();

                for (int i = 0; i < 4; i++) {
                    if (isValid(nodex + dx[i], nodey + dy[i], grid)) {
                        // This fresh orange is marked rotten in the grid and pushed into the queue.
                        grid[nodex + dx[i]][nodey + dy[i]] = 2;
                        rotten.push({nodex + dx[i], nodey + dy[i]});
                        fresh--;
                    }
                }
            }
        }
        // If any fresh orange still remains, return -1.
        if (fresh > 0)return -1;
        /**
         * Else return (ans - 1), reducing ans by 1 because the last set of rotten oranges in the queue will not
         * have any adjacent fresh oranges to rot but the loop will still increment 1 to our ans.
        */
        return ans - 1;
    }
};
