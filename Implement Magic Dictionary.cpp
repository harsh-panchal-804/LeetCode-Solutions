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



class MagicDictionary {
public:
    Trie* trie;
    MagicDictionary() {
        trie=new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto i : dictionary){
            trie->insert(i);
        }
    }
    
    bool search(string searchWord) {
    for(int i = 0; i < searchWord.size(); i++) {
        char originalChar = searchWord[i];
        for(int j = 0; j < 26; j++) {
            char newChar = 'a' + j;
            if(newChar == originalChar) continue;  
            searchWord[i] = newChar; 
            if(trie->search(searchWord)) {
                return true;  
            }
        }
        searchWord[i] = originalChar;  
    }
    return false;
    }

    };


/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */