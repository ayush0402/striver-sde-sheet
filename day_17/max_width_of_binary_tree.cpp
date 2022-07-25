// First solution will give WA in case of int overflows of indexes.

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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)return 0;
        queue <pair<TreeNode*, int>> q;
        // {node, index}
        q.push({root, 0});
        int width = 1;
        while (!q.empty()) {
            int sz = q.size();
            int minindex = q.front().second;
            int maxindex = minindex;
            while (sz--) {
                auto ele = q.front();
                q.pop();
                TreeNode* node = ele.first;
                int index = ele.second;
                if (sz == 0)maxindex = index;
                if (node->left != NULL)q.push({node->left, 2 * (index) + 1});
                if (node->right != NULL)q.push({node->right, 2 * (index) + 2});
            }
            width = max(width, maxindex - minindex + 1);
        }
        return width;
    }
};

// Optimised solution for int overflows.
/**
 * Optimised solution includes subtracting first(min) index of each level from an index
 * before using it to calculate next level's indices and pushing them into the queue.
 * This maintains the order of numbers "1 2 3 4 5 ..." on each level reducing the chances
 * of int overflow.
 */

/*
Note: leetcode's TC still give RE due to int overflow even after this optimisation. Hence
      Hence requires to use long long int instead for AC.
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if (root == NULL)return 0;
        queue <pair<TreeNode*, int>> q;
        // {node, index}
        q.push({root, 0});
        int width = 1;
        while (!q.empty()) {
            int sz = q.size();
            int lastminindex = q.front().second;
            int minindex, maxindex;
            for (int i = 0; i < sz; i++) {
                int index = q.front().second - lastminindex;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0)minindex = index;
                if (i == sz - 1)maxindex = index;
                if (node->left != NULL)q.push({node->left, (2 * index) + 1});
                if (node->right != NULL)q.push({node->right, (2 * index) + 2});

            }
            width = max(width, maxindex - minindex + 1);
        }
        return width;
    }
};
