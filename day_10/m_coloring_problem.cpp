//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    bool possibleColor(int node, int _color, vector <int>& color, bool graph[101][101], int n) {
        for (int k = 0; k <= n; k++) {
            if (k == node || graph[k][node] == 0)continue;
            if (color[k] == _color)return false;
        }
        return true;
    }

    bool recur(int node, bool graph[101][101], int m, int n, vector<int>& color) {
        for (int _color = 1; _color <= m; _color++) {
            if (possibleColor(node, _color, color, graph, n)) {
                if (node == n)return true;
                color[node] = _color;
                if (recur(node + 1, graph, m, n, color))return true;
                color[node] = -1;
            }
        }
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector <int> color(n + 1 , -1);
        if (recur(0, graph, m, n, color))return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    bool possibleColor(int node, int _color, vector <int>& color, bool graph[101][101], int n) {
        for (int k = 0; k <= n; k++) {
            if (k == node || graph[k][node] == 0)continue;
            if (color[k] == _color)return false;
        }
        return true;
    }

    bool recur(int node, bool graph[101][101], int m, int n, vector<int>& color) {
        for (int _color = 1; _color <= m; _color++) {
            if (possibleColor(node, _color, color, graph, n)) {
                if (node == n)return true;
                color[node] = _color;
                if (recur(node + 1, graph, m, n, color))return true;
                color[node] = -1;
            }
        }
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector <int> color(n + 1 , -1);
        if (recur(0, graph, m, n, color))return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
