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
    bool helper(TreeNode* node, long long minn, long long maxx) {
        if (node->val >= maxx || node->val <= minn)return false;
        int lv = true, rv = true;
        if (node->left)
            lv = helper(node->left, minn, node->val);
        if (lv == false)return false;
        if (node->right)
            rv = helper(node->right, node->val, maxx);
        if (rv == false)return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
