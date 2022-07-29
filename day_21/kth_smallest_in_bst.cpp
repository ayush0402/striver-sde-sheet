/*
Bruteforce : Iterating all nodes and storing them in a data structure
then sorting the data structues.
TC : O(N) + O(NlogN)
SC : O(N)
*/

/*
Doing inorder traversal and storing in a data structure.
As inorder traversal returns elements in sorted order in a BST.

TC : O(N)
SC : O(N)
*/

/*
Optimised solution will be using morris inorder traversal to improve
space complexity.
*/

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
	int kthSmallest(TreeNode* root, int k) {
		TreeNode* cur = root;
		int count = 0;
		int ans = 0;
		while (cur != NULL) {
			if (cur->left == NULL) {
				count++;
				if (count == k) {
					ans = cur->val;
				}
				cur = cur->right;
			}
			else {
				TreeNode* prev = cur->left;
				while (prev->right != NULL && prev->right != cur) {
					prev = prev->right;
				}
				if (prev->right == NULL) {
					prev->right = cur;
					cur = cur->left;
				}
				else {
					prev->right = NULL;
					count++;
					if (count == k) {
						ans = cur->val;
					}
					cur = cur->right;
				}
			}
		}
		return ans;
	}
};
