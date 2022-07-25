/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool helper(vector<int>& path, TreeNode* node, int B) {
    if (node == NULL)return false;

    path.push_back(node->val);
    if (node->val == B) {
        return true;
    }

    if (helper(path, node->left, B)) {
        return true;
    }

    if (helper(path, node->right, B)) {
        return true;
    }

    path.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector <int> path;
    helper(path, A, B);
    return path;
}
