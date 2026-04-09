#include<bits/stdc++.h>
class Trie {
public:
    bool flag;
    Trie* children[26];

    Trie() {
        memset(children, 0, sizeof(children));
        flag = false;
    }
};

class WordDictionary {
public:
    Trie* root;

    WordDictionary() {
        root = new Trie();
    }

    void addWord(string word) {
        Trie* node = root;
        for (auto &i : word) {
            if (node->children[i - 'a'] == nullptr) {
                node->children[i - 'a'] = new Trie();
            }
            node = node->children[i - 'a'];
        }
        node->flag = true;
    }

    bool search(string word) {
        return searchWord(word, root, 0);
    }

    bool searchWord(string word, Trie* node, int ind) {
        if (ind == word.size()) return node->flag;

        char ch = word[ind];

        if (ch != '.') {
            if (node->children[ch - 'a'] == nullptr)
                return false;
            return searchWord(word, node->children[ch - 'a'], ind + 1);
        }

        for (int j = 0; j < 26; ++j) {
            if (node->children[j] != nullptr) {
                if (searchWord(word, node->children[j], ind + 1))
                    return true;
            }
        }

        return false;
    }
};