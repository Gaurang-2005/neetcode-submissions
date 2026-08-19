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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ;

        auto temp = root;

        while (temp -> val != p -> val) {
            pathP.push_back(temp);
            if (p -> val < temp -> val) {
                temp = temp -> left;
                continue;
            }
            else if (p -> val > temp -> val) {
                temp = temp -> right;
                continue;
            }
        }
        pathP.push_back(temp);
        temp = root;
        while (temp -> val != q -> val) {
            pathQ.push_back(temp);
            if (q -> val < temp -> val) {
                temp = temp -> left;
                continue;
            }
            else if (q -> val > temp -> val) {
                temp = temp -> right;
                continue;
            }
        }
        pathQ.push_back(temp);
        vector<TreeNode*> min, max;
        if (pathP.size() < pathQ.size()) {
            min = pathP;
            max = pathQ;
        }
        else {
            max = pathP;
            min = pathQ;
        }
        for (int i = max.size() - 1; i >= 0; i--) {
            for (int j = min.size() - 1; j >= 0; j--) {
                if (min[j] == max[i]) return min[j];
            }
        } 
        return nullptr;        
    }
};