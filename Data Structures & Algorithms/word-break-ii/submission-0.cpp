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

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto &word : wordDict){
            Insert(word);
        }

        vector<string> ans;
        string temp = "";

        find(s, ans, 0, temp);

        return ans;
    }

    void find(string &s, vector<string>& ans, int ind, string &temp){
        if(ind == s.size()){
            temp.pop_back();   
            ans.push_back(temp);
            temp.push_back(' '); 
            return;
        }

        Trie* node = root;

        for(int i = ind; i < s.size(); ++i){
            if(node->children[s[i]-'a'] == nullptr)
                break;

            node = node->children[s[i]-'a'];
            temp.push_back(s[i]);

            if(node->flag){
                temp.push_back(' ');
                find(s, ans, i+1, temp);
                temp.pop_back();
            }
        }

        while(temp.size() && temp.back() != ' ')
            temp.pop_back();
    }

    void Insert(string &word){
        Trie* node = root;

        for(char c : word){
            if(node->children[c-'a'] == nullptr)
                node->children[c-'a'] = new Trie();

            node = node->children[c-'a'];
        }

        node->flag = true;
    }
};