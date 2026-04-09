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
    unordered_map<TreeNode*, int> dp;
    int maxRob(TreeNode* root)
    {
        if(root == nullptr) return 0;
        if(dp.count(root)) return dp[root];
        int ans = root->val;
        int a=0,b=0;
        if(root->left)
        a=maxRob(root->left->left)+maxRob(root->left->right);
        if(root->right)
        b=maxRob(root->right->left)+maxRob(root->right->right);

        ans = max(ans+a+b, maxRob(root->left)+maxRob(root->right));

        return dp[root]=ans;
    }
    int rob(TreeNode* root) {
        return maxRob(root);
    }
};