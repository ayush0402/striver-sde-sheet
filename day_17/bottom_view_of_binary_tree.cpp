class Solution {
public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map <int, int> mep;
        queue <pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            Node* node = q.front().first;
            int verticalindex = q.front().second;
            q.pop();
            mep[verticalindex] = node->data;
            if (node->left != NULL) {
                q.push({node->left, verticalindex - 1});
            }
            if (node->right != NULL) {
                q.push({node->right, verticalindex + 1});
            }
        }
        vector <int> res;
        for (auto x : mep) {
            res.push_back(x.second);
        }
        return res;
    }
};
