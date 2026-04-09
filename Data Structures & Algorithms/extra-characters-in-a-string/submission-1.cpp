#include<bits/stdc++.h>
class Trie{
    public:
    bool isComplete;
    Trie* children[26];
    Trie()
    {
        isComplete = false;
        memset(children,0,sizeof(children));
    }
};
class Solution {
public:
    int dp[51];
    Trie* root = new Trie();
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp,-1,sizeof(dp));
        for(auto &word:dictionary){
            insert(word);
        }
        return find(s,0);
    }

    int find(string &s, int ind)
    {
        if(ind == s.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        int ans = 1+find(s,ind+1);

        Trie* node = root;
        for(int j = ind; j < s.size(); ++j)
        {
            char ch = s[j];
            if(!node->children[ch-'a']) break;

            node=node->children[ch-'a'];

            if(node->isComplete == true){
                ans=min(ans,find(s,j+1));
            }
        }

        return dp[ind]=ans;
    }
    void insert(string &word)
    {
        Trie* node = root;
        for(auto &ch : word){
            if(node->children[ch-'a'] == nullptr)
                node->children[ch-'a'] = new Trie();
            node=node->children[ch-'a'];
        }
        node->isComplete = true;
    }
};