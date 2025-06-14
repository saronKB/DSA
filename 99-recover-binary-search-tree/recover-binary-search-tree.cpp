class Solution {
public:
    void inorderTraversal(TreeNode* currentNode, TreeNode*& previousNode,
                          TreeNode*& firstMisplacedNode, TreeNode*& secondMisplacedNode) {
        if (!currentNode) return;

        inorderTraversal(currentNode->left, previousNode, firstMisplacedNode, secondMisplacedNode);

        if (previousNode && currentNode->val < previousNode->val) {
            if (!firstMisplacedNode) {
                firstMisplacedNode = previousNode;
                secondMisplacedNode = currentNode;
            } else {
                secondMisplacedNode = currentNode;
                return;
            }
        }

        previousNode = currentNode;

        inorderTraversal(currentNode->right, previousNode, firstMisplacedNode, secondMisplacedNode);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* previousNode = nullptr;
        TreeNode* firstMisplacedNode = nullptr;
        TreeNode* secondMisplacedNode = nullptr;

        inorderTraversal(root, previousNode, firstMisplacedNode, secondMisplacedNode);

        swap(firstMisplacedNode->val, secondMisplacedNode->val);
    }
};