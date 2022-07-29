// recursion
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
	void helper(TreeNode* root, vector<int>& ans) {
		if (root == NULL)return;
		ans.push_back(root->val);
		helper(root->left, ans);
		helper(root->right, ans);
	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector <int> ans;
		helper(root, ans);
		return ans;
	}
};

// Iterative

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
	vector<int> preorderTraversal(TreeNode* root) {
		vector <int> preorder;
		if (root == NULL)return preorder;

		stack <TreeNode*> st;
		TreeNode* node = root;
		st.push(node);
		while (!st.empty()) {
			node = st.top();
			st.pop();
			preorder.push_back(node->val);
			if (node->right != NULL) {
				st.push(node->right);
			}
			if (node->left != NULL) {
				st.push(node->left);
			}
		}
		return preorder;
	}
};

// Morris Traversal

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		TreeNode* cur = root;
		vector <int> preorder;
		while (cur != NULL) {
			if (cur->left == NULL) {
				preorder.push_back(cur->val);
				cur = cur->right;
			}
			else {
				TreeNode* prev = cur->left;
				while (prev->right != NULL && prev->right != cur) {
					prev = prev->right;
				}
				if (prev->right == NULL) {
					prev->right = cur;
					preorder.push_back(cur->val);
					cur = cur->left;
				}
				else {
					prev->right = NULL;
					cur = cur->right;
				}
			}

		}
		return preorder;
	}
};
