/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode*> visited;
    vector<int> result;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParentMap(root, nullptr);
        dfs(target, k);

        return result;
    }

    void buildParentMap(TreeNode* node, TreeNode* par) {
        if (!node) return;
        parent[node] = par;
        buildParentMap(node->left, node);
        buildParentMap(node->right, node);
    }

    void dfs(TreeNode* node, int k) {
        if (!node || visited.count(node)) return;

        visited.insert(node);
        if (k == 0) {
            result.push_back(node->val);
            return;
        }

        dfs(node->left, k - 1);
        dfs(node->right, k - 1);
        dfs(parent[node], k - 1);
    }
};