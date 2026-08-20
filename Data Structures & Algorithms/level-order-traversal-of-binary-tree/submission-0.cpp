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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<vector<int>> out;
        vector<TreeNode*> temp;
        temp.push_back(root);
        while (true) {
            vector<TreeNode*> next;
            vector<int> sub;
            for (auto& i : temp) {
                if (i) {
                    sub.push_back(i -> val);
                    next.push_back(i -> left);
                    next.push_back(i -> right);
                }
            }
            temp = next;
            if (sub.size() == 0) break;
            out.push_back(sub);
        }        
        return out;
    }
};
