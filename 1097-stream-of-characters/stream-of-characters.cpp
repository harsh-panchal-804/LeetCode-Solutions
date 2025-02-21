class TrieNode{
    public:
    bool eow;
    vector<TrieNode*> child;
    TrieNode(){
        child.resize(26,nullptr);
        eow=false;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
    void insert(string &a ){
        TrieNode* curr=root;
        for(int i=a.size()-1;i>=0;i--){
            if(curr->child[a[i]-'a']==nullptr){
               curr->child[a[i]-'a']=new TrieNode(); 
            }
            curr=curr->child[a[i]-'a'];
        }
        curr->eow=true;

    }
    bool search(string& w) {
        TrieNode* node=root;
      
        for(int i=w.size()-1;i>=0;i--){
            int idx = w[i] - 'a';
            if (!node->child[idx]) {
                return false;
            }
            node = node->child[idx];
            if(node->eow)return true;
           
        }
        return false;
    }
};





class StreamChecker {
public:
    Trie trie;
    string querystr="";
    StreamChecker(vector<string>& words) {
        for(auto i : words){
            trie.insert(i);
        }
    }
    
    bool query(char letter) {
        querystr+=letter;
        return trie.search(querystr);
        
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */