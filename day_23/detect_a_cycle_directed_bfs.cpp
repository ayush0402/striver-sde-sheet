
class Solution {


public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> arr[numCourses];

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            arr[u].push_back(v);
        }

        vector <int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                indegree[arr[i][j]]++;
            }
        }

        queue <int> q;
        int cnt = 0;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) {
                q.push(i);
                cnt++;
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int child : arr[node]) {
                indegree[child]--;
                if (!indegree[child]) {
                    q.push(child);
                    cnt++;
                }
            }
        }

        if (cnt == numCourses)return true;
        else return false;

    }
};
