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
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */