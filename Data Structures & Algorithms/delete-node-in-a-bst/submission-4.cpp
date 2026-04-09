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
    TreeNode* removeNode(TreeNode* root, int key)
    {
        if(root == nullptr) return nullptr;
        if(root->val > key)
        root->left = removeNode(root->left, key);
        else if(root->val < key)
        root->right = removeNode(root->right,key);
        else
        {
            // cout << "inside key matches value block" << endl;
            if(root->left == nullptr) return root->right;
            else if(root->right == nullptr) return root->left;
            else
            {
                TreeNode* node = root->right;
                TreeNode* temp = node;
                while(node->left != nullptr){
                    node=node->left;
                }
                node->left = root->left;
                delete(root);
                return temp;
            }
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return removeNode(root, key);
    }
};