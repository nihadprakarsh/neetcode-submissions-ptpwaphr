#include<bits/stdc++.h>
using namespace std;

class Trie{
public:
    bool flag;
    Trie* children[26];
    Trie(){
        flag = false;
        memset(children, 0, sizeof(children));
    }
};

class Solution {
public:
    Trie* root = new Trie();
    vector<int> dp;

    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto &word: dictionary){
            insertWord(word);
        }

        int n = s.size();
        dp.resize(n, -1);

        return solve(s, 0);
    }

    void insertWord(string &word){
        Trie* node = root;
        for(auto &c: word){
            if(node->children[c - 'a'] == nullptr)
                node->children[c - 'a'] = new Trie();
            node = node->children[c - 'a'];
        }
        node->flag = true;
    }

    int solve(string &s, int i){
        if(i >= s.size()) return 0;

        if(dp[i] != -1) return dp[i];

        // Option 1: skip current char
        int ans = 1 + solve(s, i + 1);

        // Option 2: match words from trie
        Trie* node = root;
        for(int j = i; j < s.size(); j++){
            if(node->children[s[j] - 'a'] == nullptr)
                break;

            node = node->children[s[j] - 'a'];

            if(node->flag){
                ans = min(ans, solve(s, j + 1));
            }
        }

        return dp[i] = ans;
    }
};