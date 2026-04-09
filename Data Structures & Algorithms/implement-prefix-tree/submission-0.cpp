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
class PrefixTree {
public:
    Trie* root = new Trie();
    PrefixTree() {
        // Trie* root = new Trie();
    }
    
    void insert(string word) {
        Trie* node = root;
        for(auto &ch:word){
            if(node->children[ch-'a'] == nullptr){
                node->children[ch-'a']=new Trie();
            }
            node=node->children[ch-'a'];
        }
        node->isComplete=true;
    }
    
    bool search(string word) {
        Trie* node = root;
        for(auto &ch:word){
            if(node->children[ch-'a'] == nullptr){
                return false;
            }
            node=node->children[ch-'a'];
        }
        return node->isComplete==true;
    }
    
    bool startsWith(string prefix) {
        Trie* node = root;
        for(auto &ch:prefix){
            if(node->children[ch-'a'] == nullptr){
                return false;
            }
            node=node->children[ch-'a'];
        }
        return true;
    }
};
