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
    bool isValidBST_min_max(TreeNode *root, int min, int max) {
        if (!root) return true;
        if (root->val <= min || root->val >= max) return false;
        return isValidBST_min_max(root->left, min, root->val) && 
               isValidBST_min_max(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST_min_max(root, INT_MIN, INT_MAX);
    }
};
