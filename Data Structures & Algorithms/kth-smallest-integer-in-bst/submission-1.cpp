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
    void reached(TreeNode* root, int& targ, int& current,int& out) {
        if (!root) return;
        reached(root -> left, targ, current, out);
        current++;
        if (current == targ) out = root -> val;
        reached(root -> right, targ, current, out);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int out;
        int current = 0;
        reached(root, k, current, out);
        return out;
    }
};
