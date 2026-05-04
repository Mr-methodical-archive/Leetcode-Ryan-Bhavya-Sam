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
        queue<TreeNode*> q;
        int num_nodes = 0;
        if (root) {
            q.push(root);
            num_nodes = 1;
        }
        vector<vector<int>> retval;
        while (!q.empty()) {
            int future = 0;
            vector<int> section;
            for (int i = 0; i < num_nodes; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                section.push_back(curr->val);
                if (curr->left) {
                    q.push(curr->left);
                    ++future;
                }
                if (curr->right) {
                    q.push(curr->right);
                    ++future;
                }
            }
            retval.push_back(section);
            num_nodes = future;
        }
        return retval;
    }
};
