/**
 * Bruteforce:
 * --------------------------------------------------------
 * Following the logic of "path from root to given node", store the paths
 * to node A and node B in two vectors respectively. Then iterate both the
 * vectors to find till where they have common ancestors.
*/

// Optimised
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)return root;
		if (root == p)return p;
		if (root == q)return q;

		TreeNode* l = lowestCommonAncestor(root->left, p, q);
		TreeNode* r = lowestCommonAncestor(root->right, p, q);
		if (l != NULL && r != NULL)return root;
		if (l == NULL && r != NULL)return r;
		if (l != NULL && r == NULL)return l;
		return NULL;

		/* Better way to write above:
		if(left == NULL)return right;
		else if(right == NULL)return left;
		else return root;
		*/
	}
};
