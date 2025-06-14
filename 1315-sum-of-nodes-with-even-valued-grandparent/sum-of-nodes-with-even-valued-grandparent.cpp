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

        if (grandparent && grandparent->val % 2 == 0) {
            sum += current->val;
        }

        sum += dfs(current->left, current, parent);
        sum += dfs(current->right, current, parent);

        return sum;
    }
};
