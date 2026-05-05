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
    TreeNode *helper(unordered_map<int, int>& um, vector<int>& preorder, vector<int>& inorder,
                     int pl, int pr, int il, int ir) {
        if (pl > pr) return nullptr;
        TreeNode *t = new TreeNode(preorder[pl]);
        // um[preorder[pl]] is index it in so um[preorder[pl]]
        int l =  um[preorder[pl]] - il;
        t->left = helper(um, preorder, inorder, pl + 1, pl + l, il, il + l - 1);
        t->right = helper(um, preorder, inorder, pl + l + 1, pr, il + l + 1, ir);
        return t;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> um;
        for (int i = 0; i < inorder.size(); ++i) {
            um[inorder[i]] = i;
        }
        return helper(um, preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
