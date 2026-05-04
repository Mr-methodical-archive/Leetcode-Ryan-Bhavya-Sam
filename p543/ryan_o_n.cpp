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
    int result = 0;
    int depth(TreeNode *root) {
        if (!root) return 0;
        int dl = depth(root->left);
        int dr = depth(root->right);
        result = max(result, dl + dr);
        return 1 + max(dl, dr);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return result;
    }
};
