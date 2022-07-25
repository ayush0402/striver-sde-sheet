/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include <bits/stdc++.h>
bool isLeaf(TreeNode<int>* node) {
    if (node->left == NULL && node->right == NULL)return true;
    return false;
}

void leftBoundary(TreeNode<int>* node, vector<int>& ans) {
    while (node != NULL) {
        if (!isLeaf(node))ans.push_back(node->data);
        if (node->left != NULL)node = node->left;
        else node = node->right;
    }
}

void leafBoundary(TreeNode<int>* node, vector<int>& ans) {
    if (isLeaf(node)) {ans.push_back(node->data); return;}
    if (node->left != NULL)leafBoundary(node->left, ans);
    if (node->right != NULL)leafBoundary(node->right, ans);
}

void rightBoundary(TreeNode<int>* node, vector<int>& ans) {
    stack <int> st;
    while (node != NULL) {
        if (!isLeaf(node))st.push(node->data);
        if (node->right)node = node->right;
        else node = node->left;
    }
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
}
vector<int> traverseBoundary(TreeNode<int>* root) {
    // Write your code here.
    vector <int> ans;
    if (root == NULL)return ans;
    if (!isLeaf(root))
        ans.push_back(root->data);
    leftBoundary(root->left, ans);
    leafBoundary(root, ans);
    rightBoundary(root->right, ans);
    return ans;
}
