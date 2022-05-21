class Solution {
public:
    bool dfs(int node, int color, vector<vector<int>>& graph, vector <int>& colorv) {
        colorv[node] = 1 - color;
        for (auto child : graph[node]) {
            if (colorv[child] == -1) {
                if (!dfs(child, 1 - color, graph, colorv))return false;
            }
            else if (colorv[child] == colorv[node]) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector <int> colorv(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (colorv[i] == -1) {
                if (!dfs(i, 0, graph, colorv))return false;
            }
        }
        return true;
    }
};
