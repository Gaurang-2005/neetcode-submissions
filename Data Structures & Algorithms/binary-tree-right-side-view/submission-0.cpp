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
    void explore(vector<int>& temp, TreeNode* n, int currDepth, int& maxDepth) {
        if (!n) return;

        if (currDepth > maxDepth) {
            temp.push_back(n -> val);
            maxDepth++;
        }
        explore(temp, n -> right, ++currDepth, maxDepth);
        explore(temp, n -> left, currDepth, maxDepth);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> out;
        int val = 0;
        explore(out, root, 1, val);
        return out;
    }
};
