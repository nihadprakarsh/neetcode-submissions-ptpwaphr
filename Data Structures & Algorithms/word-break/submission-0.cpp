#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    Trie* children[26];
    bool flag;

    Trie() {
        flag = false;
        memset(children, 0, sizeof(children));
    }
};

class Solution {
public:
    Trie* root = new Trie();

    bool wordBreak(string s, vector<string>& wordDict) {

        for (auto &word : wordDict) {
            Insert(word);
        }

        vector<int> dp(s.size(), -1);

        return find(0, s, dp);
    }

    bool find(int ind, string &s, vector<int> &dp) {

        if (ind == s.size())
            return true;

        if (dp[ind] != -1)
            return dp[ind];

        Trie* node = root;

        for (int i = ind; i < s.size(); ++i) {

            char ch = s[i];

            if (node->children[ch - 'a'] == nullptr)
                break;

            node = node->children[ch - 'a'];
            if (node->flag) {

                if (find(i + 1, s, dp))
                    return dp[ind] = true;
            }
        }

        return dp[ind] = false;
    }

    void Insert(string &s) {

        Trie* node = root;

        for (auto &ch : s) {

            if (node->children[ch - 'a'] == nullptr)
                node->children[ch - 'a'] = new Trie();

            node = node->children[ch - 'a'];
        }

        node->flag = true;
    }
};