#include <bits/stdc++.h>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
	int vis[n + 1] = {0};
	vector <int> arr[n + 1];
	for (int i = 0; i < m; i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			queue <pair<int, int>> q;
			q.push({i, -1});
			vis[i] = 1;
			while (!q.empty()) {
				int node = q.front().first;
				int parent = q.front().second;
				q.pop();
				for (auto child : arr[node]) {
					if (!vis[child]) {
						q.push({child, node});
						vis[child] = 1;
					}
					else if (child != parent) {
						return "Yes";
					}
				}
			}

		}
	}
	return "No";
}
