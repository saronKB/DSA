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
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }

    int dfs(TreeNode* current, TreeNode* parent, TreeNode* grandparent) {
        if (!current) return 0;

        int sum = 0;

        // Check if grandparent exists and has even value
        if (grandparent && grandparent->val % 2 == 0) {
            sum += current->val;
        }

        // Recurse to left and right child
        sum += dfs(current->left, current, parent);
        sum += dfs(current->right, current, parent);

        return sum;
    }
};