/*
	Method 1:
	Bruteforce:
	Manually iterate and assign nodes in O(N^2)
*/

/*
	Method 2:
	sort the given preorder to obtain the inorder for the given BST.
	Construct the BST using the given preorder and inorder in O(NlogN) time.
*/

// Optimised:
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
	TreeNode* helper(vector <int>& preorder, int bound, int& i) {
		if (i == preorder.size() || bound < preorder[i]) {
			return NULL;
		}
		TreeNode* root = new TreeNode(preorder[i++]);
		root->left = helper(preorder, root->val, i);
		root->right = helper(preorder, bound, i);
		return root;
	}
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		int i = 0;
		return helper(preorder, INT_MAX, i);
	}
};
