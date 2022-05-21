class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector <int> color(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == -1) {
                // bfs here
                queue <int> q;
                q.push(i);
                color[i] = 0;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (auto child : graph[node]) {
                        if (color[child] == -1) {
                            q.push(child);
                            color[child] = 1 - color[node];
                        }
                        else if (color[child] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
