/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
#include <bits/stdc++.h>
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root) {
    vector<vector<int>> ans;
    if (root == NULL)return ans;
    vector <int> inorder;
    vector <int> preorder;
    vector <int> postorder;

    stack <pair<BinaryTreeNode<int>*, int>> st;
    st.push({root, 1});
    while (!st.empty()) {
        BinaryTreeNode<int>* node = st.top().first;
        int num = st.top().second;
        st.pop();
        if (num == 1) {
            preorder.push_back(node->data);
            num++;
            st.push({node, num});
            if (node->left != NULL)
                st.push({node->left, 1});
        }
        else if (num == 2) {
            inorder.push_back(node->data);
            num++;
            st.push({node, num});
            if (node->right != NULL)
                st.push({node->right, 1});
        }
        else {
            postorder.push_back(node->data);
        }
    }
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;
}
