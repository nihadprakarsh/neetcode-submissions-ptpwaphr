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
class WordDictionary {
public:
    Trie* root = new Trie();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
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
        return searchWord(word,node,0);
    }

    bool searchWord(string &word, Trie* node, int ind)
    {
        if(node->isComplete == true and ind == word.size()) return true;
        if(ind >= word.size()) return node->isComplete;
        char ch = word[ind];
        if(ch == '.'){
            for(int i =0 ; i < 26; ++i)
            {
                if(node->children[i]!=nullptr){
                    if(searchWord(word,node->children[i],ind+1))
                        return true;
                }
            }
        }
        else{
            if(node->children[ch-'a'] != nullptr)
                if (searchWord(word,node->children[ch-'a'],ind+1))
                    return true;
        }

        return false;
    }
};
