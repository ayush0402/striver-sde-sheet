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
    TreeNode* constructTree(vector <int>& inorder, vector <int>& postorder, map <int, int>& inordermap, int inStart, int inEnd, int postStart, int postEnd) {
        if (postStart > postEnd || inStart > inEnd)return NULL;

        TreeNode* node = new TreeNode(postorder[postEnd]);

        int inorderindex = inordermap[postorder[postEnd]];
        int toLeft = inorderindex - inStart;
        int toRight = inorder.size() - toLeft - 1;

        node->left =
            constructTree(inorder, postorder, inordermap, inStart, inorderindex - 1, postStart, postStart + toLeft - 1);
        node->right =
            constructTree(inorder, postorder, inordermap, inorderindex + 1, inEnd, postStart + toLeft, postEnd - 1);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inStart = 0, inEnd = inorder.size() - 1;
        int postStart = 0, postEnd = postorder.size() - 1;

        map <int, int> inordermap;
        for (int i = 0; i < inorder.size(); i++)inordermap[inorder[i]] = i;

        return constructTree(inorder, postorder, inordermap, inStart, inEnd, postStart, postEnd);
    }
};
