#include <bits/stdc++.h>
vector <int> arr[5001];
int vis[5001];

bool dfsCycle(int node, int parent) {
    vis[node] = 1;
    for (auto child : arr[node]) {
        if (!vis[child]) {
            if (dfsCycle(child, node))return true;
        }
        else if (child != parent)return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    for (int i = 0; i <= n; i++) {
        vis[i] = 0;
        arr[i].clear();
    }
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfsCycle(i, -1))return "Yes";
        }
    }
    return "No";
}
