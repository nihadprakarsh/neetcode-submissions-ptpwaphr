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
    int find(TreeNode* root, int value)
    {
        if(root == nullptr) return 0;
        int ans = 0;
        if(root ->val >= value){
            ans++;
        }

        value = max(value, root->val);
        return find(root->left,value) + find(root->right,value) + ans;

    }
    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        return find(root,INT_MIN);
    }
};
