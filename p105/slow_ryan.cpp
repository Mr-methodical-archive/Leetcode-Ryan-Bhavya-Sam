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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        TreeNode *head = new TreeNode(preorder[0]);
        int i = 0; 
        while (inorder[i] != preorder[0]) {
            ++i;
        }
        vector<int> inorder_left;
        vector<int> inorder_right;
        for (int j = 0; j < i; ++j) {
            inorder_left.push_back(inorder[j]);
        }
        for (int j = i + 1; j < inorder.size();++j) {
            inorder_right.push_back(inorder[j]);
        }
        vector<int> preorder_left;
        vector<int> preorder_right;
        for (int j = 1; j < i + 1; ++j) {
            preorder_left.push_back(preorder[j]);
        }
        for (int j= i + 1; j < preorder.size(); ++j) {
            preorder_right.push_back(preorder[j]);
        }
        head->left = buildTree(preorder_left, inorder_left);
        head->right = buildTree(preorder_right, inorder_right);
        return head;
    }
};
