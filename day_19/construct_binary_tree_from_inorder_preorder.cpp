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
    TreeNode* constructTree(vector <int>& preorder, vector <int>& inorder, map <int, int>& inordermap, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd)return NULL;
        TreeNode* node = new TreeNode(preorder[preStart]);

        int inorderindex = inordermap[preorder[preStart]];
        int countToLeft = inorderindex - inStart;

        node->left = constructTree(preorder, inorder, inordermap, preStart + 1, preStart + countToLeft, inStart, inorderindex - 1);
        node->right = constructTree(preorder, inorder, inordermap, preStart + countToLeft + 1, preEnd, inorderindex + 1, inEnd);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart = 0;
        int preEnd = preorder.size() - 1;
        int inStart = 0;
        int inEnd = inorder.size() - 1;

        map <int, int> inordermap;
        for (int i = 0; i < inorder.size(); i++) {
            inordermap[inorder[i]] = i;
        }

        return constructTree(preorder, inorder, inordermap, preStart, preEnd, inStart, inEnd);
    }
};
