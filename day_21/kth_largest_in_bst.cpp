// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
public:
    int kthLargest(Node *root, int k)
    {
        //Your code here
        int totalNodes = 0;

        Node* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                totalNodes++;
                curr = curr->right;
            }
            else {
                Node* prev = curr->left;
                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }
                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                }
                else {
                    prev->right = NULL;
                    totalNodes++;
                    curr = curr->right;
                }
            }
        }

        k = totalNodes - k + 1;

        curr = root;
        int count = 0;
        int ans = 0;
        while (curr != NULL) {
            if (curr->left == NULL) {
                count++;
                if (count == k) {
                    ans = curr->data;
                }
                curr = curr->right;
            }
            else {
                Node* prev = curr->left;
                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }
                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                }
                else {
                    prev->right = NULL;
                    count++;
                    if (count == k) {
                        ans = curr->data;
                    }
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
