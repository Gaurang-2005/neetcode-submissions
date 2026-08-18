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
    bool isSame(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        else if (root1 && !root2 || !root1 && root2) return false;
        else {
            if (root1 -> val == root2 -> val) {
                return isSame(root1 -> left, root2 -> left) && isSame(root1 -> right, root2 -> right);
            }
            else return false;
        }
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (root -> val != subRoot -> val) {
            return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
        }
        else {
            if (isSame(root, subRoot)) {
                return true;
            }
            else {
                return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
            }

        }
    }
};
