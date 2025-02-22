#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    int weight;
    TrieNode() {
        children.resize(27, nullptr); 
        weight = 0;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string &word, int index) {
        TrieNode* node = root;
        node->weight = index;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr) 
                node->children[idx] = new TrieNode();
            node = node->children[idx];
            node->weight = index;
        }
    }
    
    int search(const string &query) {
        TrieNode* node = root;
        for (char ch : query) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr) return -1;
            node = node->children[idx];
        }
        return node->weight;
    }
};

class WordFilter {
public:
    Trie trie;
    
    WordFilter(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string word = words[i] + "{";
            for (int j = 0; j < word.size(); j++) {
                trie.insert(word.substr(j) + words[i], i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return trie.search(suffix + "{" + prefix);
    }
};
