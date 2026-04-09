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
    int ans = INT_MIN;
    int f(TreeNode* root){
        if(root == nullptr) return 0;

        int left = f(root->left);
        int right = f(root->right);

        left = left >= 0? left : 0;
        right = right >= 0 ? right : 0;
        

        // cout << left << " " << right << " " << root->val << endl;
        ans = max(ans,left+right+root->val);

        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        f(root);
        return ans;
    }
};
