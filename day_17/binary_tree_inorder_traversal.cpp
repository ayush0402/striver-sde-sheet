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
	void helper(TreeNode* root, vector <int>& ans) {
		if (root == NULL)return;
		helper(root->left, ans);
		ans.push_back(root->val);
		helper(root->right, ans);
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector <int> ans;
		helper(root, ans);
		return ans;
	}
};

// Iterative

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector <int> inorder;
		stack <TreeNode*> st;
		TreeNode* node = root;
		while (true) {
			if (node != NULL) {
				st.push(node);
				node = node->left;
			}
			else {
				if (st.empty())break;
				node = st.top();
				st.pop();
				inorder.push_back(node->val);
				node = node->right;
			}
		}
		return inorder;
	}
};

// Morris Traversal

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		TreeNode* cur = root;
		vector <int> inorder;
		while (cur != NULL) {
			if (cur->left == NULL) {
				inorder.push_back(cur->val);
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
					inorder.push_back(cur->val);
					cur = cur->right;
				}
			}
		}
		return inorder;
	}
};
