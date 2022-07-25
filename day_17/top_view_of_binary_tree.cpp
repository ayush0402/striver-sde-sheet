class Solution
{
public:
    //Function to return a list of nodes visible from the top view
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // using concept of vertical lines from vertical order traversal.
        map <int, int> mep;
        // vertical index , Node*

        //traversing using level order traversal.

        queue <pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto ele = q.front();
            q.pop();
            Node* node = ele.first;
            int verticalindex = ele.second;
            if (mep.find(verticalindex) == mep.end()) {
                mep[verticalindex] = node->data;
            }
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
