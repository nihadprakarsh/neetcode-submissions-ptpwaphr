#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    bool flag;
    Trie* children[26];

    Trie() {
        flag = false;
        memset(children, 0, sizeof(children));
    }
};

class Solution {
public:
    Trie* root = new Trie();
    vector<string> ans;

    void insertWord(string &word) {
        Trie* node = root;
        for (char c : word) {
            if (node->children[c - 'a'] == nullptr)
                node->children[c - 'a'] = new Trie();
            node = node->children[c - 'a'];
        }
        node->flag = true;
    }

    void dfs(int i, int j, Trie* node, vector<vector<char>>& board, string &str) {
        int n = board.size(), m = board[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '#')
            return;

        char ch = board[i][j];

        if (node->children[ch - 'a'] == nullptr)
            return;

        node = node->children[ch - 'a'];
        str.push_back(ch);

        if (node->flag) {
            ans.push_back(str);
            node->flag = false; 
        }

        board[i][j] = '#';

        dfs(i + 1, j, node, board, str);
        dfs(i - 1, j, node, board, str);
        dfs(i, j + 1, node, board, str);
        dfs(i, j - 1, node, board, str);

        board[i][j] = ch;
        str.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto &word : words) {
            insertWord(word);
        }

        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                string str = "";
                dfs(i, j, root, board, str);
            }
        }

        return ans;
    }
};