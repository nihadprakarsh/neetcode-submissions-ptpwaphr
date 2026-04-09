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
    bool find(TreeNode* root, int min, int max)
    {
        if(root == nullptr) return true;
        if(root->val <= min or root->val >= max)
        return false;

        auto left = find(root->left, min, root->val);
        auto right = find(root->right, root->val, max);

        return left and right;
    }
    bool isValidBST(TreeNode* root) {
        return find(root,INT_MIN,INT_MAX);
    }
};
