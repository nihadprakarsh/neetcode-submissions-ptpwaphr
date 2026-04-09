#include<bits/stdc++.h>
class Trie{
public:
    bool isComplete;
    Trie* children[26];

    Trie() {
        isComplete = false;
        memset(children, 0, sizeof(children));
    }
};

class Solution {
public:
    Trie* root = new Trie();
    vector<string> ans;
    int n, m;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto &word: words)
            insert(word);

        n = board.size();
        m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                find(i, j, board, root, vis, "");
            }
        }
        return ans;
    }

    void find(int i, int j, vector<vector<char>>& board,
              Trie* node, vector<vector<int>>& vis, string temp) {

        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j])
            return;

        char ch = board[i][j];

        if(node->children[ch - 'a'] == nullptr)
            return;

        node = node->children[ch - 'a'];
        temp.push_back(ch);

        if(node->isComplete) {
            ans.push_back(temp);
            node->isComplete = false; 
        }

        vis[i][j] = 1;

        find(i+1, j, board, node, vis, temp);
        find(i-1, j, board, node, vis, temp);
        find(i, j+1, board, node, vis, temp);
        find(i, j-1, board, node, vis, temp);

        vis[i][j] = 0; // backtrack
    }

    void insert(string &word) {
        Trie* node = root;
        for(char ch : word) {
            if(node->children[ch - 'a'] == nullptr)
                node->children[ch - 'a'] = new Trie();
            node = node->children[ch - 'a'];
        }
        node->isComplete = true;
    }
};
