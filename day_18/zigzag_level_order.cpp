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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)return ans;
        queue <TreeNode*> q;
        q.push(root);
        bool flag = true;
        while (!q.empty()) {
            int sz = q.size();
            vector <int> temp(sz);
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                int index;
                if (flag) index = i; else index = sz - i - 1;
                temp[index] = node->val;
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            flag = !flag;
            ans.push_back(temp);
        }
        return ans;
    }
};
