/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)return res;
        // using level order traversal to populate the map
        map <int, map<int, multiset<int>>>mep;
        // vertical index, level index, values
        queue <pair<int, pair<int, TreeNode*>>> q;
        mep[0][0].insert(root->val);
        q.push({0, {0, root}});
        while (!q.empty()) {
            auto ele = q.front();
            q.pop();
            if (ele.second.second->left != NULL) {
                q.push({ele.first - 1, {ele.second.first + 1, ele.second.second->left}});
                mep[ele.first - 1][ele.second.first + 1].insert(ele.second.second->left->val);
            }
            if (ele.second.second->right != NULL) {
                q.push({ele.first + 1, {ele.second.first + 1, ele.second.second->right}});
                mep[ele.first + 1][ele.second.first + 1].insert(ele.second.second->right->val);
            }
        }
        for (auto vertical : mep) {
            vector <int> temp;
            auto mep2 = vertical.second;
            for (auto levels : mep2) {
                auto multiset1 = levels.second;
                for (auto x : multiset1) {
                    temp.push_back(x);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
