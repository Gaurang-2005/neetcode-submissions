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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (!(isBalanced(root -> left) && isBalanced(root -> right))) return false;
        auto right = maxDepth(root -> left);
        auto left = maxDepth(root -> right);
        if (right - left <= 1 && right - left >= -1) return true;
        return false;
    }
};