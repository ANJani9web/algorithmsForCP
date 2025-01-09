#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    bool endofWord;
    TrieNode* children[26];

    // Constructore to initialize a trie node
    TrieNode()
    {
        endofWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
      root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(auto it  : word){
            int index = it - 'a';
            if(!temp->children[index]){
                temp->children[index] = new TrieNode();
            }
            temp = temp->children[index];
        }
        temp->endofWord = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(auto it : word){
            int index = it - 'a';
            if(!temp->children[index]){
                return false;
            }
            temp = temp->children[index];
        }
        return temp->endofWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(auto it : prefix){
            int index = it - 'a';
            if(!temp->children[index]) return false;
            temp = temp->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */