/* BST Node
struct Node
{
    int key;
    struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively

void setPre(Node* root, Node*& pre, int k) {
    if (root == NULL)return;
    while (root != NULL) {
        if (k <= root->key) {
            root = root->left;
        }
        else {
            pre = root;
            root = root->right;
        }
    }
}

void setSuc(Node* root, Node*& suc, int k) {
    if (root == NULL)return;
    while (root != NULL) {
        if (k < root->key) {
            suc = root;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
    setSuc(root, suc, key);
    setPre(root, pre, key);
}
