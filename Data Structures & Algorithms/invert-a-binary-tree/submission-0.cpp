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
    void invert(TreeNode* parent) {
        if (!parent) return;
        if (parent -> left) invert(parent -> left);
        if (parent -> right) invert(parent -> right);
        if (!parent -> left && !parent -> right) return;

        if (parent -> left && parent -> right) {
            auto temp = parent -> left;
            parent -> left = parent -> right;
            parent -> right = temp;
        }
        else if (parent -> left && !parent -> right) {
            parent -> right = parent -> left;
            parent -> left = nullptr;
        }
        else if (!parent -> left && parent -> right) {
            parent -> left = parent -> right;
            parent -> right = nullptr;
        }
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};
