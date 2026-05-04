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
    int depth(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(depth(root->right), depth(root->left));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        int depth_left = depth(root->left);
        int depth_right = depth(root->right);
        int adding_new_node = depth_left + depth_right;
        return max(left, max(right, adding_new_node));
    }
};
