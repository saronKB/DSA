class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int total = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while (!q.empty()) {
            auto [node, num] = q.front();
            q.pop();
            if (!node->left && !node->right) {
                total += num;
            }
            if (node->left) {
                q.push({node->left, num * 10 + node->left->val});
            }
            if (node->right) {
                q.push({node->right, num * 10 + node->right->val});
            }
        }
        return total;
    }
};