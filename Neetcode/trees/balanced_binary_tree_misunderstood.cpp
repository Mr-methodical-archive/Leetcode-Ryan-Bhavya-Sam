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
    int curr_deep = -1;
    int curr_shallow = -1;
    int curr_depth = 0;
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right) {
            curr_deep = max(curr_depth, curr_deep);
            if (curr_shallow == -1) curr_shallow = curr_depth;
            else curr_shallow = min(curr_shallow, curr_depth);
            curr_depth--; // since we are going back up a level
            if (curr_deep - curr_shallow > 1) {
                return false;
            } else {
                return true;
            }
        }
        curr_depth++; // else in any other situation we are going down a level 
        bool result = true;
        if (root->right) {
            curr_depth++; // since we are going down
            result = result && isBalanced(root->right);
        }
        if (root->left) {
            curr_depth++; // we are going down again
            result = result && isBalanced(root->left);
        }
        curr_depth--; // we are going back up
        return result;
    }
};

