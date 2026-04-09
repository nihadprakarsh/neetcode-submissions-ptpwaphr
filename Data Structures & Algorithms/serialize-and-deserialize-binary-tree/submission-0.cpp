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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        queue<TreeNode*> q;
        q.push(root);
        string str = "";
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node == nullptr){
                str+="#,";
            }
            else{
                str+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        stringstream ss(data);
        string temp = "";
        getline(ss,temp,',');
        TreeNode* node = new TreeNode(stoi(temp));
        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty())
        {
            auto root = q.front();
            q.pop();
            getline(ss,temp,',');
            if(temp == "#"){
                root->left=nullptr;
            }
            else{
                root->left = new TreeNode(stoi(temp));
                q.push(root->left);
            }

            getline(ss,temp,',');
            if(temp == "#"){
                root->right=nullptr;
            }
            else{
                root->right = new TreeNode(stoi(temp));
                q.push(root->right);
            }
        }

        return node;
    }
};
