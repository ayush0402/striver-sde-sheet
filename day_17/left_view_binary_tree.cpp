/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// Iterative

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    // Your code here
    vector <int> res;
    if (root == NULL)return res;
    queue <Node*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        int flag = 1;
        while (sz--) {
            Node* node = q.front();
            q.pop();
            if (flag)res.push_back(node->data), flag = 0;
            if (node->left != NULL)q.push(node->left);
            if (node->right != NULL)q.push(node->right);
        }
    }
    return res;
}

// Recursive

//Function to return a list containing elements of left view of the binary tree.
void helper(Node* node, int level, vector <int>& res) {
    if (node == NULL)return;

    if (level == res.size())res.push_back(node->data);

    helper(node->left, level + 1, res);
    helper(node->right, level + 1, res);
}
vector<int> leftView(Node *root)
{
    // Your code here
    vector <int> res;
    helper(root, 0, res);
    return res;
}
