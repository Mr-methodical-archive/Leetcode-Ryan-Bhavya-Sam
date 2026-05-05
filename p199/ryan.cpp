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
    vector<int> rightSideView(TreeNode* root) {
        // We do a q and just always pick the right thing on each level
        queue<TreeNode *> q;
        if (root) {
            q.push(root);
        }
        vector<int> retval;
        while (!q.empty()) {
            int level_size = q.size();
            int node_back = 0;
            for (int i = 0; i < level_size; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
                node_back = curr->val;
            }
            retval.push_back(node_back);
        }
        return retval;
    }
};
