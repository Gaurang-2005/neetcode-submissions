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
    int stop = INT_MIN;
    int pathSum(TreeNode* root) {
        if (!root) return 0;
        int left = 0, right = 0;
        bool l = false, r = false;
        if (root -> left) {
            left = max(0, pathSum(root -> left));
        }
        if (root -> right) {
            right = max(0, pathSum(root -> right));
        }
        stop = max(stop, left + right + root -> val);
        int out = max(left, right) + root -> val;
        return out;
    }
public:
    int maxPathSum(TreeNode* root) {
        return max(stop, pathSum(root));
    }
};
