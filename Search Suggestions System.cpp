class TrieNode{
   public: 
    vector<TrieNode*> child;
    bool eow;
    TrieNode(){
        child.resize(26,nullptr);
        eow=false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    void insert(string word) {
        TrieNode* curr=root;
        for(auto & ch: word){
            if(curr->child[ch-'a']==nullptr){
                TrieNode* node=new TrieNode();
                curr->child[ch-'a']=node;
            }
            curr=curr->child[ch-'a'];
        }
        curr->eow=true;
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        for(auto & i: word){
            if(curr->child[i-'a']==nullptr)return false;
            curr=curr->child[i-'a'];
        }
        return curr->eow;

    }
    
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        for(auto & i: prefix){
            if(curr->child[i-'a']==nullptr)return false;
            curr=curr->child[i-'a'];
        }
        return true;
    }
    void dfs(TrieNode* curr,string & word,vector<string>& ans){
        if(ans.size()>=3)return;
        ///preorder traverse
        if(curr->eow)ans.push_back(word);
        for(int i=0;i<26;i++){
           if(curr->child[i]){
                word+=('a'+i);
                dfs(curr->child[i],word,ans);
                word.pop_back();
           }
        }
        return;
    }
    vector<string> getWords(string & prefix){
        TrieNode* curr=root;
        vector<string> ans;
        for(char & c: prefix){
            if(!curr->child[c-'a'])return ans;
            curr=curr->child[c-'a'];
        }
        dfs(curr,prefix,ans);
        return ans;
    }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string search) {
        Trie* trie=new Trie();
        for(auto i : products){
            trie->insert(i);
        }
        vector<vector<string>> ans;
        for(int i=0;i<search.size();i++){
            string x=search.substr(0,i+1);
            vector<string> tans=trie->getWords(x);
            ans.push_back(tans);
        }
        return ans;
    }
};