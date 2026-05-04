/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *ans = nullptr;
    TreeNode *helper(TreeNode*root, TreeNode *p, TreeNode *q) {
        // idea is we tell what we have
        // maybe another case when root is a node
        if (!root) return nullptr;
        TreeNode *left = helper(root->left, p, q);
        TreeNode *right = helper(root->right, p, q);
        if (root == p || root == q) {
            if (left || right) {
                ans = root;
                return nullptr;
            } else {
                return root;
            }
        }
        if (left && right) {
            ans = root;
            return nullptr;
        } else if (!left && !right) {
            return nullptr;
        } else if (left) {
            return left;
        } else {
            return right;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // we could return what we still need
        // ex. if we don't have either we return nullptr
        //     If we have one but not the other then we show which one we still need
        // actually, pivoting, we send what we have back up, when we have both of what we need we edit the global
        // because send we send nullptr up after and we can't contain duplicates
        helper(root, p, q);
        return ans;
    }
};
