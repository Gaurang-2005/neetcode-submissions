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
    void count(TreeNode* root, int& cnt, int max) {
        if (!root) return;
        if (max <= root -> val) {
            cnt++;
            max = root -> val;
        }

        count(root -> right, cnt, max);
        count(root -> left, cnt, max);
    }
public:
    int goodNodes(TreeNode* root) {
        int out = 0;
        count(root, out, -101);
        return out;
    }
};
