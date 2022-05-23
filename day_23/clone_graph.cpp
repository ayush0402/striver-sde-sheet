/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map <Node*, Node*> mep;
    map <Node*, int> vis;
    void dfs(Node* node) {
        vis[node] = 1;
        Node* n = new Node(node->val);
        mep[node] = n;
        for (auto x : node->neighbors) {
            if (!vis[x]) {
                dfs(x);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if (node == NULL)return NULL;
        dfs(node);
        for (auto [x, y] : mep) {
            vector <Node*> temp;
            for (auto i : x->neighbors) {
                temp.push_back(mep[i]);
            }
            y->neighbors = temp;
        }
        return mep[node];
    }
};
